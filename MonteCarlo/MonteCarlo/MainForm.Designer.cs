namespace MonteCarlo
{
   partial class MainForm
   {
      /// <summary>
      ///  Required designer variable.
      /// </summary>
      private System.ComponentModel.IContainer components = null;

      /// <summary>
      ///  Clean up any resources being used.
      /// </summary>
      /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
      protected override void Dispose(bool disposing)
      {
         if (disposing && (components != null))
         {
            components.Dispose();
         }
         base.Dispose(disposing);
      }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            buttonGenerateInputFile = new Button();
            labelStartX = new Label();
            labelEndX = new Label();
            textBoxStartX = new TextBox();
            textBoxEndX = new TextBox();
            labelN = new Label();
            textBoxN = new TextBox();
            label1 = new Label();
            comboBoxLanguage = new ComboBox();
            buttonCalculateFunctionsArea = new Button();
            tabControl1 = new TabControl();
            tabPage1 = new TabPage();
            labelCsharpTicks = new Label();
            labelCppTicks = new Label();
            labelAsemblerTicks = new Label();
            labelCsharpMilliseconds = new Label();
            labelCppMilliseconds = new Label();
            labelAsemblerMilliseconds = new Label();
            label11 = new Label();
            label10 = new Label();
            label9 = new Label();
            checkBoxLogicalProcessors = new CheckBox();
            textBoxThreads = new TextBox();
            label8 = new Label();
            progressBarFiles = new ProgressBar();
            tabPage2 = new TabPage();
            comboBoxSingleLanguage = new ComboBox();
            labelSingleLanguage = new Label();
            progressBarSingle = new ProgressBar();
            textBoxSingleN = new TextBox();
            label7 = new Label();
            buttonCalcArea = new Button();
            labelArea = new Label();
            label6 = new Label();
            textBoxSingleStartX = new TextBox();
            label5 = new Label();
            textBoxSingleEndX = new TextBox();
            label4 = new Label();
            label3 = new Label();
            textBoxB = new TextBox();
            label2 = new Label();
            textBoxA = new TextBox();
            labelX = new Label();
            tabControl1.SuspendLayout();
            tabPage1.SuspendLayout();
            tabPage2.SuspendLayout();
            SuspendLayout();
            // 
            // buttonGenerateInputFile
            // 
            buttonGenerateInputFile.Font = new Font("Verdana", 12F);
            buttonGenerateInputFile.Location = new Point(8, 8);
            buttonGenerateInputFile.Margin = new Padding(3, 4, 3, 4);
            buttonGenerateInputFile.Name = "buttonGenerateInputFile";
            buttonGenerateInputFile.Size = new Size(385, 49);
            buttonGenerateInputFile.TabIndex = 0;
            buttonGenerateInputFile.Text = "Generuj plik wejściowy";
            buttonGenerateInputFile.UseVisualStyleBackColor = true;
            buttonGenerateInputFile.Click += buttonGenerateInputFile_Click;
            // 
            // labelStartX
            // 
            labelStartX.AutoSize = true;
            labelStartX.Font = new Font("Verdana", 12F);
            labelStartX.Location = new Point(8, 72);
            labelStartX.Name = "labelStartX";
            labelStartX.Size = new Size(159, 25);
            labelStartX.TabIndex = 1;
            labelStartX.Text = "X początkowy:";
            // 
            // labelEndX
            // 
            labelEndX.AutoSize = true;
            labelEndX.Font = new Font("Verdana", 12F);
            labelEndX.Location = new Point(227, 72);
            labelEndX.Name = "labelEndX";
            labelEndX.Size = new Size(129, 25);
            labelEndX.TabIndex = 2;
            labelEndX.Text = "X końcowy:";
            // 
            // textBoxStartX
            // 
            textBoxStartX.Font = new Font("Verdana", 9.75F);
            textBoxStartX.Location = new Point(173, 75);
            textBoxStartX.Margin = new Padding(3, 4, 3, 4);
            textBoxStartX.Name = "textBoxStartX";
            textBoxStartX.Size = new Size(43, 27);
            textBoxStartX.TabIndex = 3;
            // 
            // textBoxEndX
            // 
            textBoxEndX.Font = new Font("Verdana", 9.75F);
            textBoxEndX.Location = new Point(362, 75);
            textBoxEndX.Margin = new Padding(3, 4, 3, 4);
            textBoxEndX.Name = "textBoxEndX";
            textBoxEndX.Size = new Size(43, 27);
            textBoxEndX.TabIndex = 4;
            // 
            // labelN
            // 
            labelN.AutoSize = true;
            labelN.Font = new Font("Verdana", 12F);
            labelN.Location = new Point(8, 111);
            labelN.Name = "labelN";
            labelN.Size = new Size(294, 25);
            labelN.TabIndex = 5;
            labelN.Text = "Liczba losowych punktów n:";
            // 
            // textBoxN
            // 
            textBoxN.Font = new Font("Verdana", 9.75F);
            textBoxN.Location = new Point(298, 111);
            textBoxN.Margin = new Padding(3, 4, 3, 4);
            textBoxN.Name = "textBoxN";
            textBoxN.Size = new Size(107, 27);
            textBoxN.TabIndex = 6;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Verdana", 12F);
            label1.Location = new Point(7, 151);
            label1.Name = "label1";
            label1.Size = new Size(240, 25);
            label1.TabIndex = 7;
            label1.Text = "Język programowania:";
            // 
            // comboBoxLanguage
            // 
            comboBoxLanguage.Font = new Font("Verdana", 9.75F);
            comboBoxLanguage.FormattingEnabled = true;
            comboBoxLanguage.Items.AddRange(new object[] { "Asembler", "C++", "C#" });
            comboBoxLanguage.Location = new Point(244, 150);
            comboBoxLanguage.Margin = new Padding(3, 4, 3, 4);
            comboBoxLanguage.Name = "comboBoxLanguage";
            comboBoxLanguage.Size = new Size(161, 26);
            comboBoxLanguage.TabIndex = 8;
            // 
            // buttonCalculateFunctionsArea
            // 
            buttonCalculateFunctionsArea.Font = new Font("Verdana", 12F);
            buttonCalculateFunctionsArea.Location = new Point(8, 230);
            buttonCalculateFunctionsArea.Margin = new Padding(3, 4, 3, 4);
            buttonCalculateFunctionsArea.Name = "buttonCalculateFunctionsArea";
            buttonCalculateFunctionsArea.Size = new Size(385, 39);
            buttonCalculateFunctionsArea.TabIndex = 9;
            buttonCalculateFunctionsArea.Text = "Oblicz pola powierzchni";
            buttonCalculateFunctionsArea.UseVisualStyleBackColor = true;
            buttonCalculateFunctionsArea.Click += buttonCalculateFunctionsArea_Click;
            // 
            // tabControl1
            // 
            tabControl1.Controls.Add(tabPage1);
            tabControl1.Controls.Add(tabPage2);
            tabControl1.Font = new Font("Verdana", 9.75F);
            tabControl1.Location = new Point(14, 16);
            tabControl1.Margin = new Padding(3, 4, 3, 4);
            tabControl1.Name = "tabControl1";
            tabControl1.SelectedIndex = 0;
            tabControl1.Size = new Size(426, 473);
            tabControl1.TabIndex = 10;
            // 
            // tabPage1
            // 
            tabPage1.Controls.Add(labelCsharpTicks);
            tabPage1.Controls.Add(labelCppTicks);
            tabPage1.Controls.Add(labelAsemblerTicks);
            tabPage1.Controls.Add(labelCsharpMilliseconds);
            tabPage1.Controls.Add(labelCppMilliseconds);
            tabPage1.Controls.Add(labelAsemblerMilliseconds);
            tabPage1.Controls.Add(label11);
            tabPage1.Controls.Add(label10);
            tabPage1.Controls.Add(label9);
            tabPage1.Controls.Add(checkBoxLogicalProcessors);
            tabPage1.Controls.Add(textBoxThreads);
            tabPage1.Controls.Add(label8);
            tabPage1.Controls.Add(progressBarFiles);
            tabPage1.Controls.Add(buttonGenerateInputFile);
            tabPage1.Controls.Add(buttonCalculateFunctionsArea);
            tabPage1.Controls.Add(labelStartX);
            tabPage1.Controls.Add(comboBoxLanguage);
            tabPage1.Controls.Add(textBoxStartX);
            tabPage1.Controls.Add(label1);
            tabPage1.Controls.Add(labelEndX);
            tabPage1.Controls.Add(textBoxN);
            tabPage1.Controls.Add(textBoxEndX);
            tabPage1.Controls.Add(labelN);
            tabPage1.Location = new Point(4, 27);
            tabPage1.Margin = new Padding(3, 4, 3, 4);
            tabPage1.Name = "tabPage1";
            tabPage1.Padding = new Padding(3, 4, 3, 4);
            tabPage1.Size = new Size(418, 442);
            tabPage1.TabIndex = 0;
            tabPage1.Text = "Plik wejściowy";
            tabPage1.UseVisualStyleBackColor = true;
            tabPage1.Click += tabPage1_Click;
            // 
            // labelCsharpTicks
            // 
            labelCsharpTicks.AutoSize = true;
            labelCsharpTicks.Font = new Font("Verdana", 9.75F);
            labelCsharpTicks.Location = new Point(286, 357);
            labelCsharpTicks.Name = "labelCsharpTicks";
            labelCsharpTicks.Size = new Size(20, 20);
            labelCsharpTicks.TabIndex = 22;
            labelCsharpTicks.Text = "0";
            // 
            // labelCppTicks
            // 
            labelCppTicks.AutoSize = true;
            labelCppTicks.Font = new Font("Verdana", 9.75F);
            labelCppTicks.Location = new Point(160, 357);
            labelCppTicks.Name = "labelCppTicks";
            labelCppTicks.Size = new Size(20, 20);
            labelCppTicks.TabIndex = 21;
            labelCppTicks.Text = "0";
            // 
            // labelAsemblerTicks
            // 
            labelAsemblerTicks.AutoSize = true;
            labelAsemblerTicks.Font = new Font("Verdana", 9.75F);
            labelAsemblerTicks.Location = new Point(8, 357);
            labelAsemblerTicks.Name = "labelAsemblerTicks";
            labelAsemblerTicks.Size = new Size(20, 20);
            labelAsemblerTicks.TabIndex = 20;
            labelAsemblerTicks.Text = "0";
            // 
            // labelCsharpMilliseconds
            // 
            labelCsharpMilliseconds.AutoSize = true;
            labelCsharpMilliseconds.Font = new Font("Verdana", 9.75F);
            labelCsharpMilliseconds.Location = new Point(286, 336);
            labelCsharpMilliseconds.Name = "labelCsharpMilliseconds";
            labelCsharpMilliseconds.Size = new Size(20, 20);
            labelCsharpMilliseconds.TabIndex = 19;
            labelCsharpMilliseconds.Text = "0";
            // 
            // labelCppMilliseconds
            // 
            labelCppMilliseconds.AutoSize = true;
            labelCppMilliseconds.Font = new Font("Verdana", 9.75F);
            labelCppMilliseconds.Location = new Point(160, 336);
            labelCppMilliseconds.Name = "labelCppMilliseconds";
            labelCppMilliseconds.Size = new Size(20, 20);
            labelCppMilliseconds.TabIndex = 18;
            labelCppMilliseconds.Text = "0";
            // 
            // labelAsemblerMilliseconds
            // 
            labelAsemblerMilliseconds.AutoSize = true;
            labelAsemblerMilliseconds.Font = new Font("Verdana", 9.75F);
            labelAsemblerMilliseconds.Location = new Point(8, 336);
            labelAsemblerMilliseconds.Name = "labelAsemblerMilliseconds";
            labelAsemblerMilliseconds.Size = new Size(20, 20);
            labelAsemblerMilliseconds.TabIndex = 17;
            labelAsemblerMilliseconds.Text = "0";
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Font = new Font("Verdana", 12F);
            label11.Location = new Point(286, 312);
            label11.Name = "label11";
            label11.Size = new Size(42, 25);
            label11.TabIndex = 16;
            label11.Text = "C#";
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Font = new Font("Verdana", 12F);
            label10.Location = new Point(160, 312);
            label10.Name = "label10";
            label10.Size = new Size(58, 25);
            label10.TabIndex = 15;
            label10.Text = "C++";
            label10.Click += label10_Click;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("Verdana", 12F);
            label9.Location = new Point(8, 312);
            label9.Name = "label9";
            label9.Size = new Size(106, 25);
            label9.TabIndex = 14;
            label9.Text = "Asembler";
            // 
            // checkBoxLogicalProcessors
            // 
            checkBoxLogicalProcessors.AutoSize = true;
            checkBoxLogicalProcessors.Location = new Point(233, 192);
            checkBoxLogicalProcessors.Margin = new Padding(3, 4, 3, 4);
            checkBoxLogicalProcessors.Name = "checkBoxLogicalProcessors";
            checkBoxLogicalProcessors.Size = new Size(189, 24);
            checkBoxLogicalProcessors.TabIndex = 13;
            checkBoxLogicalProcessors.Text = "Procesory logiczne";
            checkBoxLogicalProcessors.UseVisualStyleBackColor = true;
            checkBoxLogicalProcessors.CheckedChanged += checkBoxLogicalProcessors_CheckedChanged;
            // 
            // textBoxThreads
            // 
            textBoxThreads.Font = new Font("Verdana", 9.75F);
            textBoxThreads.Location = new Point(90, 189);
            textBoxThreads.Margin = new Padding(3, 4, 3, 4);
            textBoxThreads.Name = "textBoxThreads";
            textBoxThreads.Size = new Size(137, 27);
            textBoxThreads.TabIndex = 12;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Font = new Font("Verdana", 12F);
            label8.Location = new Point(8, 189);
            label8.Name = "label8";
            label8.Size = new Size(79, 25);
            label8.TabIndex = 11;
            label8.Text = "Wątki:";
            // 
            // progressBarFiles
            // 
            progressBarFiles.Location = new Point(8, 277);
            progressBarFiles.Margin = new Padding(3, 4, 3, 4);
            progressBarFiles.Name = "progressBarFiles";
            progressBarFiles.Size = new Size(385, 31);
            progressBarFiles.TabIndex = 10;
            // 
            // tabPage2
            // 
            tabPage2.Controls.Add(comboBoxSingleLanguage);
            tabPage2.Controls.Add(labelSingleLanguage);
            tabPage2.Controls.Add(progressBarSingle);
            tabPage2.Controls.Add(textBoxSingleN);
            tabPage2.Controls.Add(label7);
            tabPage2.Controls.Add(buttonCalcArea);
            tabPage2.Controls.Add(labelArea);
            tabPage2.Controls.Add(label6);
            tabPage2.Controls.Add(textBoxSingleStartX);
            tabPage2.Controls.Add(label5);
            tabPage2.Controls.Add(textBoxSingleEndX);
            tabPage2.Controls.Add(label4);
            tabPage2.Controls.Add(label3);
            tabPage2.Controls.Add(textBoxB);
            tabPage2.Controls.Add(label2);
            tabPage2.Controls.Add(textBoxA);
            tabPage2.Controls.Add(labelX);
            tabPage2.Location = new Point(4, 27);
            tabPage2.Margin = new Padding(3, 4, 3, 4);
            tabPage2.Name = "tabPage2";
            tabPage2.Padding = new Padding(3, 4, 3, 4);
            tabPage2.Size = new Size(418, 442);
            tabPage2.TabIndex = 1;
            tabPage2.Text = "Pojedyncza funkcja";
            tabPage2.UseVisualStyleBackColor = true;
            // 
            // comboBoxSingleLanguage
            // 
            comboBoxSingleLanguage.Font = new Font("Verdana", 9.75F);
            comboBoxSingleLanguage.FormattingEnabled = true;
            comboBoxSingleLanguage.Items.AddRange(new object[] { "Asembler", "C++", "C#" });
            comboBoxSingleLanguage.Location = new Point(251, 188);
            comboBoxSingleLanguage.Margin = new Padding(3, 4, 3, 4);
            comboBoxSingleLanguage.Name = "comboBoxSingleLanguage";
            comboBoxSingleLanguage.Size = new Size(161, 26);
            comboBoxSingleLanguage.TabIndex = 16;
            // 
            // labelSingleLanguage
            // 
            labelSingleLanguage.AutoSize = true;
            labelSingleLanguage.Font = new Font("Verdana", 12F);
            labelSingleLanguage.Location = new Point(8, 188);
            labelSingleLanguage.Name = "labelSingleLanguage";
            labelSingleLanguage.Size = new Size(240, 25);
            labelSingleLanguage.TabIndex = 15;
            labelSingleLanguage.Text = "Język programowania:";
            // 
            // progressBarSingle
            // 
            progressBarSingle.Location = new Point(7, 273);
            progressBarSingle.Margin = new Padding(3, 4, 3, 4);
            progressBarSingle.Name = "progressBarSingle";
            progressBarSingle.Size = new Size(385, 31);
            progressBarSingle.TabIndex = 14;
            // 
            // textBoxSingleN
            // 
            textBoxSingleN.Font = new Font("Verdana", 9.75F);
            textBoxSingleN.Location = new Point(305, 147);
            textBoxSingleN.Margin = new Padding(3, 4, 3, 4);
            textBoxSingleN.Name = "textBoxSingleN";
            textBoxSingleN.Size = new Size(107, 27);
            textBoxSingleN.TabIndex = 13;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Verdana", 12F);
            label7.Location = new Point(7, 147);
            label7.Name = "label7";
            label7.Size = new Size(294, 25);
            label7.TabIndex = 12;
            label7.Text = "Liczba losowych punktów n:";
            // 
            // buttonCalcArea
            // 
            buttonCalcArea.Font = new Font("Verdana", 12F);
            buttonCalcArea.Location = new Point(7, 224);
            buttonCalcArea.Margin = new Padding(3, 4, 3, 4);
            buttonCalcArea.Name = "buttonCalcArea";
            buttonCalcArea.Size = new Size(195, 41);
            buttonCalcArea.TabIndex = 11;
            buttonCalcArea.Text = "Oblicz pole";
            buttonCalcArea.UseVisualStyleBackColor = true;
            buttonCalcArea.Click += buttonCalcArea_Click;
            // 
            // labelArea
            // 
            labelArea.AutoSize = true;
            labelArea.Font = new Font("Verdana", 12F);
            labelArea.Location = new Point(280, 232);
            labelArea.Name = "labelArea";
            labelArea.Size = new Size(25, 25);
            labelArea.TabIndex = 10;
            labelArea.Text = "0";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Verdana", 12F);
            label6.Location = new Point(209, 232);
            label6.Name = "label6";
            label6.Size = new Size(70, 25);
            label6.TabIndex = 9;
            label6.Text = "Pole: ";
            // 
            // textBoxSingleStartX
            // 
            textBoxSingleStartX.Font = new Font("Verdana", 9.75F);
            textBoxSingleStartX.Location = new Point(159, 80);
            textBoxSingleStartX.Margin = new Padding(3, 4, 3, 4);
            textBoxSingleStartX.Name = "textBoxSingleStartX";
            textBoxSingleStartX.Size = new Size(43, 27);
            textBoxSingleStartX.TabIndex = 7;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Verdana", 12F);
            label5.Location = new Point(7, 117);
            label5.Name = "label5";
            label5.Size = new Size(129, 25);
            label5.TabIndex = 6;
            label5.Text = "X końcowy:";
            // 
            // textBoxSingleEndX
            // 
            textBoxSingleEndX.Font = new Font("Verdana", 9.75F);
            textBoxSingleEndX.Location = new Point(159, 120);
            textBoxSingleEndX.Margin = new Padding(3, 4, 3, 4);
            textBoxSingleEndX.Name = "textBoxSingleEndX";
            textBoxSingleEndX.Size = new Size(43, 27);
            textBoxSingleEndX.TabIndex = 8;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Verdana", 12F);
            label4.Location = new Point(7, 80);
            label4.Name = "label4";
            label4.Size = new Size(159, 25);
            label4.TabIndex = 5;
            label4.Text = "X początkowy:";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Verdana", 12F);
            label3.Location = new Point(7, 40);
            label3.Name = "label3";
            label3.Size = new Size(79, 25);
            label3.TabIndex = 4;
            label3.Text = "f(x) = ";
            // 
            // textBoxB
            // 
            textBoxB.Location = new Point(171, 40);
            textBoxB.Margin = new Padding(3, 4, 3, 4);
            textBoxB.Name = "textBoxB";
            textBoxB.Size = new Size(31, 27);
            textBoxB.TabIndex = 3;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Verdana", 12F);
            label2.Location = new Point(7, 4);
            label2.Name = "label2";
            label2.Size = new Size(91, 25);
            label2.TabIndex = 2;
            label2.Text = "Funkcja";
            // 
            // textBoxA
            // 
            textBoxA.Location = new Point(86, 40);
            textBoxA.Margin = new Padding(3, 4, 3, 4);
            textBoxA.Name = "textBoxA";
            textBoxA.Size = new Size(31, 27);
            textBoxA.TabIndex = 1;
            // 
            // labelX
            // 
            labelX.AutoSize = true;
            labelX.Font = new Font("Verdana", 12F);
            labelX.Location = new Point(123, 40);
            labelX.Name = "labelX";
            labelX.Size = new Size(54, 25);
            labelX.TabIndex = 0;
            labelX.Text = "x + ";
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(462, 505);
            Controls.Add(tabControl1);
            Margin = new Padding(3, 4, 3, 4);
            Name = "MainForm";
            Text = "Całkowanie Monte Carlo";
            Load += MainForm_Load;
            tabControl1.ResumeLayout(false);
            tabPage1.ResumeLayout(false);
            tabPage1.PerformLayout();
            tabPage2.ResumeLayout(false);
            tabPage2.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private Button buttonGenerateInputFile;
      private Label labelStartX;
      private Label labelEndX;
      private TextBox textBoxStartX;
      private TextBox textBoxEndX;
      private Label labelN;
      private TextBox textBoxN;
      private Label label1;
      private ComboBox comboBoxLanguage;
      private Button buttonCalculateFunctionsArea;
      private TabControl tabControl1;
      private TabPage tabPage1;
      private TabPage tabPage2;
      private Label label2;
      private TextBox textBoxA;
      private Label labelX;
      private Label label3;
      private TextBox textBoxB;
      private Label label4;
      private TextBox textBoxSingleStartX;
      private Label label5;
      private TextBox textBoxSingleEndX;
      private Label labelArea;
      private Label label6;
      private Button buttonCalcArea;
      private TextBox textBoxSingleN;
      private Label label7;
      private ProgressBar progressBarFiles;
      private ProgressBar progressBarSingle;
      private TextBox textBoxThreads;
      private Label label8;
      private CheckBox checkBoxLogicalProcessors;
      private ComboBox comboBoxSingleLanguage;
      private Label labelSingleLanguage;
      private Label label10;
      private Label label9;
      private Label labelCsharpTicks;
      private Label labelCppTicks;
      private Label labelAsemblerTicks;
      private Label labelCsharpMilliseconds;
      private Label labelCppMilliseconds;
      private Label labelAsemblerMilliseconds;
      private Label label11;
   }
}
