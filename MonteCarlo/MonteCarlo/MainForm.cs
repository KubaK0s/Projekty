using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Security;
using System.Threading;
using static System.Runtime.InteropServices.JavaScript.JSType;
using static System.Windows.Forms.AxHost;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Rebar;

[assembly: AllowPartiallyTrustedCallers]

namespace MonteCarlo
{
   public partial class MainForm : Form
   {
      private struct Function
      {
         public int Slope;
         public int Intercept;
         public int StartX;
         public int EndX;
         public int MinY;
         public int MaxY;
      }

      private int CalcY(Function function, int x)
      {
         return function.Slope * x + function.Intercept;
      }

      public MainForm()
      {
         InitializeComponent();
      }

      [DllImport("MonteCarloAsm.dll", CallingConvention = CallingConvention.Cdecl)]

      private static extern int MonteCarloAsm(int[] randX, int[] randY,
         int n, int[] function);

      [DllImport("MonteCarloCpp.dll", CallingConvention = CallingConvention.Cdecl)]

      private static extern int MonteCarloCpp(int[] randX, int[] randY,
         int n,
         int slope, int intercept,
         int startX, int endX,
         int minY, int maxY);

      private int MonteCarloCsh(int[] randX, int[] randY,
         int n,
         int slope, int intercept,
         int startX, int endX,
         int minY, int maxY)
      {
         int area = 0;
         int c = 0;
         for (int i = 0; i < n; ++i)
         {
            int fx = slope * randX[i] + intercept;
            if (randY[i] > 0 && randY[i] <= fx)
            {
               ++c;
            }
            else if (randY[i] < 0 && randY[i] >= fx)
            {
               --c;
            }
         }

         area = (endX - startX) * (maxY - minY) * c / n;
         return area;
      }

      private void buttonGenerateInputFile_Click(object sender, EventArgs e)
      {
         string outputPath = "funkcje.txt";
         int numberOfFunctions = 64;
         using (StreamWriter sw = new StreamWriter(outputPath))
         {
            Random random = new Random();

            for (int i = 0; i < numberOfFunctions; i++)
            {
               int a = random.Next(-10, 11);
               int b = random.Next(-10, 11);

               string function = $"{a}x {(b >= 0 ? '+' : '-')} {Math.Abs(b)}";

               sw.WriteLine(function);
            }
         }

         MessageBox.Show($"Plik {outputPath} zosta³ wygenerowany z {numberOfFunctions} losowymi funkcjami.");
      }

      private static Function ParseFunction(string functionString)
      {
         string[] parts = functionString.Split(new char[] { 'x', ' ' }, StringSplitOptions.RemoveEmptyEntries);

         if (parts.Length == 3)
         {
            int slope = int.Parse(parts[0]);
            int intercept = int.Parse(parts[2]);

            if (parts[1] == "-")
            {
               intercept = -intercept;
            }

            return new Function { Slope = slope, Intercept = intercept };
         }

         throw new ArgumentException("Nieprawid³owy format funkcji.");
      }

      private void MainForm_Load(object sender, EventArgs e)
      {
         //files
         textBoxStartX.Text = "0";
         textBoxEndX.Text = "20";
         textBoxN.Text = "1000";
         textBoxThreads.Text = Environment.ProcessorCount.ToString();
         textBoxThreads.Enabled = false;
         checkBoxLogicalProcessors.Checked = true;
         comboBoxLanguage.SelectedIndex = 0;

         //single function
         textBoxA.Text = "1";
         textBoxB.Text = "0";
         textBoxSingleStartX.Text = "0";
         textBoxSingleEndX.Text = "20";
         textBoxSingleN.Text = "1000";
         comboBoxSingleLanguage.SelectedIndex = 0;
      }

      private async void buttonCalculateFunctionsArea_Click(object sender, EventArgs e)
      {
         //pobieranie x pocz¹tkowego
         int startX = 0;
         bool result = int.TryParse(textBoxStartX.Text.ToString(), out startX);
         if (!result)
         {
            MessageBox.Show($"Nie uda³o siê poprawnie pobraæ wartoœci x pocz¹tkowego.");
            return;
         }

         //pobieranie x koñcowego
         int endX = 0;
         result = int.TryParse(textBoxEndX.Text.ToString(), out endX);
         if (!result)
         {
            MessageBox.Show($"Nie uda³o siê poprawnie pobraæ wartoœci x koñcowego.");
            return;
         }

         if (startX >= endX)
         {
            MessageBox.Show($"X pocz¹tkowy musi byæ mniejszy od x koñcowego!");
            return;
         }

         //pobieranie n losowych punktów
         int n = 0;
         result = int.TryParse(textBoxN.Text.ToString(), out n);
         if (!result || n < 1)
         {
            MessageBox.Show($"Nie uda³o siê poprawnie pobraæ wartoœci n, n musi byæ wiêksze od 0.");
            return;
         }

         int threads = 0;
         result = int.TryParse(textBoxThreads.Text.ToString(), out threads);
         if (!result || threads < 1 || threads > 64)
         {
            MessageBox.Show($"Liczba w¹tków musi byæ wiêksza od 0 i mniejsza od 65.");
            return;
         }

         //wczytywanie funkcji
         string inputPath = "funkcje.txt";
         if (!File.Exists(inputPath))
         {
            MessageBox.Show("Nie uda³o siê wczytaæ funkcji. Plik funkcje.txt nie istnieje.");
            return;
         }

         List<Function> functions = new List<Function>();
         using (StreamReader sr = new StreamReader(inputPath))
         {
            string line;
            while ((line = sr.ReadLine()) != null)
            {
               Function function = ParseFunction(line);
               function.MinY = Math.Min(CalcY(function, startX), CalcY(function, endX));
               function.MaxY = Math.Max(CalcY(function, startX), CalcY(function, endX));
               functions.Add(function);
            }
         }

         Stopwatch watch = new Stopwatch();
         watch.Start();
         int[] areas = new int[functions.Count];
         List<Task> tasks = new List<Task>();
         int language = comboBoxLanguage.SelectedIndex;
         double progress = 0.0;
         progressBarFiles.Value = 0;
         for (int thread = 0; thread < threads; thread++)
         {
            int threadNr = thread;
            int functionsPerThread = functions.Count / threads;
            int functionsPerLastThread = functionsPerThread + functions.Count % threads;
            tasks.Add(Task.Run(() =>
            {
               int startFunctionNr = functionsPerThread * threadNr;
               if (threadNr == threads - 1)
               {
                  functionsPerThread = functionsPerLastThread;
               }
               for (int functionNr = startFunctionNr; functionNr < startFunctionNr + functionsPerThread; functionNr++)
               {
                  int[] randX = new int[n];
                  int[] randY = new int[n];
                  Random random = new Random();
                  for (int i = 0; i < n; i++)
                  {
                     randX[i] = random.Next(startX, endX);
                     randY[i] = random.Next(functions[functionNr].MinY, functions[functionNr].MaxY);
                  }
                  if (language == 0)
                  {
                     int[] arr = new int[6];
                     arr[0] = functions[functionNr].Slope;
                     arr[1] = functions[functionNr].Intercept;
                     arr[2] = startX;
                     arr[3] = endX;
                     arr[4] = functions[functionNr].MinY;
                     arr[5] = functions[functionNr].MaxY;
                     areas[functionNr] = MonteCarloAsm(randX, randY,
                        n, arr);
                  }
                  else if (language == 1)
                  {
                     areas[functionNr] = Math.Abs(MonteCarloCpp(randX, randY,
                        n, functions[functionNr].Slope,
                        functions[functionNr].Intercept,
                        startX, endX, functions[functionNr].MinY,
                        functions[functionNr].MaxY));
                  }
                  else if (language == 2)
                  {
                     areas[functionNr] = Math.Abs(MonteCarloCsh(randX, randY,
                        n, functions[functionNr].Slope,
                        functions[functionNr].Intercept,
                        startX, endX, functions[functionNr].MinY,
                        functions[functionNr].MaxY));
                  }
                  progress += 100.0 / (double)functions.Count;
                  UpdateProgressBar(Math.Min(100, (int)progress));
               }
            }));
         }
         await Task.WhenAll(tasks);

         string outputPath = "wyniki";
         string langStr = "";
         if (language == 0)
         {
            langStr = "asembler";
         }
         else if (language == 1)
         {
            langStr = "cpp";
         }
         else if (language == 2)
         {
            langStr = "csharp";
         }
         outputPath += "_" + langStr + ".txt";

         using (StreamWriter sw = new StreamWriter(outputPath))
         {
            Random random = new Random();

            sw.WriteLine($"xp: {startX}, xk: {endX}, w¹tki: {threads}, n: {n}");
            for (int i = 0; i < areas.Length; i++)
            {
               if (areas[i] != 0)
               {
                  string resultArea = $"{functions[i].Slope}x" +
                     $" {(functions[i].Intercept >= 0 ? '+' : '-')}" +
                     $" {Math.Abs(functions[i].Intercept)}," +
                     $" pole: {areas[i]}";
                  sw.WriteLine(resultArea);
               }
            }
         }

         long milliseconds = watch.ElapsedMilliseconds;
         long ticks = watch.ElapsedTicks;
         if (language == 0)
         {
            labelAsemblerMilliseconds.Text = milliseconds.ToString() + " ms";
            labelAsemblerTicks.Text = ticks.ToString() + " tiki";
         }
         else if (language == 1)
         {
            labelCppMilliseconds.Text = milliseconds.ToString() + " ms";
            labelCppTicks.Text = ticks.ToString() + " tiki";
         }
         else if (language == 2)
         {
            labelCsharpMilliseconds.Text = milliseconds.ToString() + " ms";
            labelCsharpTicks.Text = ticks.ToString() + " tiki";
         }


         MessageBox.Show($"Obliczono pola dla funkcji, wyniki zosta³y zapisane do pliku wyniki_{langStr}.txt");
      }

      private void checkBoxLogicalProcessors_CheckedChanged(object sender, EventArgs e)
      {
         if (checkBoxLogicalProcessors.Checked == true)
         {
            textBoxThreads.Text = Environment.ProcessorCount.ToString();
            textBoxThreads.Enabled = false;
         }
         else
         {
            textBoxThreads.Enabled = true;
         }
      }

      private void tabPage1_Click(object sender, EventArgs e)
      {

      }

      private void buttonCalcArea_Click(object sender, EventArgs e)
      {
         progressBarSingle.Value = 0;
         //pobieranie a
         int slope = 0;
         bool result = int.TryParse(textBoxA.Text.ToString(), out slope);
         if (!result)
         {
            MessageBox.Show($"Nie uda³o siê poprawnie pobraæ wartoœci a.");
            return;
         }

         progressBarSingle.Value = 10;

         //pobieranie b
         int intercept = 0;
         result = int.TryParse(textBoxB.Text.ToString(), out intercept);
         if (!result)
         {
            MessageBox.Show($"Nie uda³o siê poprawnie pobraæ wartoœci b.");
            return;
         }

         progressBarSingle.Value = 20;

         //pobieranie n
         int n = 0;
         result = int.TryParse(textBoxSingleN.Text.ToString(), out n);
         if (!result || n < 1)
         {
            MessageBox.Show($"Nie uda³o siê poprawnie pobraæ wartoœci n.");
            return;
         }

         progressBarSingle.Value = 30;

         //pobieranie x poczatkowego
         int startX = 0;
         result = int.TryParse(textBoxSingleStartX.Text.ToString(), out startX);
         if (!result)
         {
            MessageBox.Show($"Nie uda³o siê poprawnie pobraæ wartoœci x pocz¹tkowego.");
            return;
         }

         progressBarSingle.Value = 40;

         //pobieranie x koñcowego
         int endX = 0;
         result = int.TryParse(textBoxSingleEndX.Text.ToString(), out endX);
         if (!result)
         {
            MessageBox.Show($"Nie uda³o siê poprawnie pobraæ wartoœci x koñcowego.");
            return;
         }

         if (startX >= endX)
         {
            MessageBox.Show($"X pocz¹tkowy musi byæ mniejszy od x koñcowego!");
            return;
         }

         progressBarSingle.Value = 50;

         Function function = new Function();
         function.Slope = slope;
         function.Intercept = intercept;
         function.MinY = Math.Min(CalcY(function, startX), CalcY(function, endX));
         function.MaxY = Math.Max(CalcY(function, startX), CalcY(function, endX));

         int[] randX = new int[n];
         int[] randY = new int[n];
         Random random = new Random();
         for (int i = 0; i < n; i++)
         {
            randX[i] = random.Next(startX, endX);
            randY[i] = random.Next(function.MinY, function.MaxY);
         }

         progressBarSingle.Value = 75;

         int language = comboBoxSingleLanguage.SelectedIndex;
         int area = 0;
         if (language == 0)
         {
            int[] arr = new int[6];
            arr[0] = function.Slope;
            arr[1] = function.Intercept;
            arr[2] = startX;
            arr[3] = endX;
            arr[4] = function.MinY;
            arr[5] = function.MaxY;
            area = MonteCarloAsm(randX, randY,
               n, arr);
         }
         else if (language == 1)
         {
            area = Math.Abs(MonteCarloCpp(randX, randY,
               n, slope, intercept, startX, endX, function.MinY, function.MaxY));
         }
         else if (language == 2)
         {
            area = Math.Abs(MonteCarloCsh(randX, randY,
               n, slope, intercept, startX, endX, function.MinY, function.MaxY));
         }

         progressBarSingle.Value = 100;

         labelArea.Text = area.ToString();
      }

      private void label10_Click(object sender, EventArgs e)
      {

      }
      private void UpdateProgressBar(int value)
      {
         if (progressBarFiles.InvokeRequired)
         {
            progressBarFiles.Invoke(new Action(() => { progressBarFiles.Value = value; }));
         }
         else
         {
            progressBarFiles.Value = value;
         }
      }
   }
}
