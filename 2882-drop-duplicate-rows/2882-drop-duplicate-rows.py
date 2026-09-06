import pandas as pd

def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    df=customers.drop_duplicates(subset=['email'])
    return df