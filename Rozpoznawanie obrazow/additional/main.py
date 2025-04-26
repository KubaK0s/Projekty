import pandas as pd

# Załaduj logi z pliku CSV
log_path = 'C:\\Users\\User\\biai\\BiaiProject\\results\\training_log.csv'
logs = pd.read_csv(log_path)

# Inicjalizuj nową kolumnę dla oszacowanego error_rate dla treningu
logs['train_error_rate_est'] = logs['error_rate'] * (logs['train_loss'] / logs['valid_loss'])

# Zapisz nowe logi do pliku z oszacowanym train_error_rate
logs.to_csv('C:\\Users\\User\\biai\\BiaiProject\\results\\training_log_with_train_error_rate.csv', index=False)

# Wyświetl oszacowane wartości
print(logs[['epoch', 'train_loss', 'valid_loss', 'error_rate', 'train_error_rate_est']])
