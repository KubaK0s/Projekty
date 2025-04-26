import os
import shutil
from sklearn.model_selection import train_test_split

def split_data(source, train, valid, split_size):
    all_files = os.listdir(source)
    train_files, valid_files = train_test_split(all_files, test_size=split_size)

    for file_name in train_files:
        shutil.copy(os.path.join(source, file_name), os.path.join(train, file_name))

    for file_name in valid_files:
        shutil.copy(os.path.join(source, file_name), os.path.join(valid, file_name))

source_ai = 'data/ai_generated'
source_human = 'data/human_made'

train_ai = 'data/train/ai_generated'
valid_ai = 'data/valid/ai_generated'
train_human = 'data/train/human_made'
valid_human = 'data/valid/human_made'

os.makedirs(train_ai, exist_ok=True)
os.makedirs(valid_ai, exist_ok=True)
os.makedirs(train_human, exist_ok=True)
os.makedirs(valid_human, exist_ok=True)

split_size = 0.2
split_data(source_ai, train_ai, valid_ai, split_size)
split_data(source_human, train_human, valid_human, split_size)

