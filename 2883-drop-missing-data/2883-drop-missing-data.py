import pandas as pd

def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    df=students.dropna(subset=['name'])
    return df