import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    students['key'] = 1
    subjects['key'] = 1
    all_combinations = students.merge(subjects, on='key').drop('key', axis=1)

    exam_counts = examinations.groupby(['student_id', 'subject_name']).size().reset_index(name='attended_exams')

    result = all_combinations.merge(exam_counts, on=['student_id', 'subject_name'], how='left')
    result['attended_exams'] = result['attended_exams'].fillna(0).astype(int)

    result = result.sort_values(['student_id', 'subject_name'])
    
    return result[['student_id', 'student_name', 'subject_name', 'attended_exams']]
