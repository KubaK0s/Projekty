import os
import matplotlib.pyplot as plt
import pandas as pd
from fastai.vision.all import *
from pathlib import Path


class CSVLoggerCallback(Callback):
    def __init__(self, fname):
        self.fname = fname
        self.logs = []

    def before_fit(self):
        self.logs.append(['epoch', 'train_loss', 'valid_loss', 'error_rate'])

    def after_epoch(self):
        if len(self.learn.recorder.values) > 0:
            epoch_log = [self.epoch]
            epoch_log += self.learn.recorder.values[-1]
            self.logs.append(epoch_log)

    def after_fit(self):
        df = pd.DataFrame(self.logs[1:], columns=self.logs[0])
        df.to_csv(self.fname, index=False)


def main():
    # Ustawienie ścieżki do danych
    path = Path('C:\\Users\\User\\biai\\BiaiProject\\data')

    # Utworzenie zestawu danych z bardziej zaawansowaną augmentacją
    batch_tfms = aug_transforms(
        mult=1.0,
        do_flip=True,
        flip_vert=True,
        max_rotate=30.0,
        max_zoom=1.1,
        max_lighting=0.2,
        max_warp=0.2,
        p_affine=0.75,  # Próbkowanie transformacji afinicznych z prawdopodobieństwem 0.75
        p_lighting=0.75  # Próbkowanie zmian oświetlenia z prawdopodobieństwem 0.75
    )

    dls = ImageDataLoaders.from_folder(
        path, train='train', valid='valid',
        item_tfms=Resize(224),
        batch_tfms=batch_tfms,
        bs=8  # Ustawienie rozmiaru batch na 32
    )

    # Szybkie spojrzenie na dane
    dls.show_batch(max_n=9, figsize=(7, 8))

    # Ścieżka do pliku CSV z logami
    csv_log_path = os.path.join('C:\\Users\\User\\biai\\BiaiProject\\results', 'training_log.csv')

    # Zdefiniowanie modelu z Dropout (np. ResNet18)
    learn = cnn_learner(dls, resnet34, metrics=error_rate, cbs=[CSVLoggerCallback(fname=csv_log_path)], wd=1e-2)

    # Trenowanie modelu
    learn.fine_tune(
        50,
        cbs=[CSVLoggerCallback(fname=csv_log_path)],  # Dodanie tylko loggera CSV
        wd=1e-2  # Weight decay
    )

    # Zapisanie wytrenowanego modelu
    try:
        learn.save('model_ai_vs_human1')
    except Exception as e:
        print(f"Saving model failed: {e}")

    # Ocena modelu
    interp = ClassificationInterpretation.from_learner(learn)
    interp.plot_confusion_matrix(figsize=(6, 6), dpi=60)

    # Zapisanie macierzy konfuzji do pliku
    try:
        save_path = os.path.join('C:\\Users\\User\\biai\\BiaiProject\\results', 'confusion_matrix.png')
        plt.savefig(save_path)
    except Exception as e:
        print(f"Saving confusion matrix failed: {e}")

    # Zamknięcie wykresu, aby zwolnić zasoby
    plt.close()

    # Wyświetlenie 9 przykładów z największymi błędami
    interp.plot_top_losses(9, figsize=(10, 10))


if __name__ == '__main__':
    main()
