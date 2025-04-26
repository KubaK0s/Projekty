import pandas as pd
import matplotlib.pyplot as plt

csv_log_path = 'C:\\Users\\User\\biai\\BiaiProject\\results\\training_log.csv'

df = pd.read_csv(csv_log_path, header=0)

df['train_loss'] = pd.to_numeric(df['train_loss'], errors='coerce')
df['valid_loss'] = pd.to_numeric(df['valid_loss'], errors='coerce')

df = df.dropna()

plt.figure(figsize=(8, 6))
plt.plot(df['epoch'], df['train_loss'], label='Train Loss', marker='o', color='b')
plt.plot(df['epoch'], df['valid_loss'], label='Valid Loss', marker='o', color='r')
plt.title('Training and Validation Loss')
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.legend()
plt.grid(True)
plt.show()





