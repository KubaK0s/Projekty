import pandas as pd
import matplotlib.pyplot as plt

# Załaduj logi z pliku CSV
log_path = 'C:\\Users\\User\\biai\\BiaiProject\\results\\training_log_with_train_error_rate.csv'
logs = pd.read_csv(log_path)

# Oblicz dokładność jako 1 - wskaźnik błędu
logs['train_accuracy_est'] = 1 - logs['train_error_rate_est']
logs['validation_accuracy'] = 1 - logs['error_rate']

# Utwórz wykres dokładności dla treningu i walidacji
plt.figure(figsize=(10, 6))

# Wykres dla train_accuracy_est
plt.plot(logs['epoch'], logs['train_accuracy_est'], label='Train Accuracy', color='blue', marker='o')

# Wykres dla validation_accuracy
plt.plot(logs['epoch'], logs['validation_accuracy'], label='Validation Accuracy', color='red', marker='o')

# Dodanie tytułu i etykiet
plt.title('Train and Validation Accuracy per Epoch')
plt.xlabel('Epoch')
plt.ylabel('Accuracy')
plt.legend()

# Wyświetlenie wykresu
plt.grid(True)
plt.show()


