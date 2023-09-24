package testClasses;

public class ResultCalculator {
    public double getGPA(int score, int total_marks) {
        try {
            if (score > total_marks) {
                throw new InvalidNumberException("Invalid Score or Total Marks: Score cannot be greater than Total Marks.");
            }
            int scoreIn100 = (int) new MyNumber().roundUp(score * 100 / total_marks);
            double gpa;

            if (scoreIn100 >= 80) gpa = 4.00;
            else if (scoreIn100 >= 75) gpa = 3.75;
            else if (scoreIn100 >= 70) gpa = 3.50;
            else if (scoreIn100 >= 65) gpa = 3.25;
            else if (scoreIn100 >= 60) gpa = 3.00;
            else if (scoreIn100 >= 55) gpa = 2.75;
            else if (scoreIn100 >= 50) gpa = 2.50;
            else if (scoreIn100 >= 45) gpa = 2.25;
            else if (scoreIn100 >= 40) gpa = 2.00;
            else gpa = 0.00;

            return gpa;
        }catch (InvalidNumberException error){
            System.out.println(error);
            return -1.00;
        }
    }

    public String getGrade(int score, int total_marks) {
        try {
            if (score > total_marks) {
                throw new InvalidNumberException("Invalid Score or Total Marks: Score cannot be greater than Total Marks.");
            }
            int scoreIn100 = (int) new MyNumber().roundUp(score * 100 / total_marks);
            String grade;

            if (scoreIn100 >= 80) grade = "A+";
            else if (scoreIn100 >= 75) grade = "A";
            else if (scoreIn100 >= 70) grade = "A-";
            else if (scoreIn100 >= 65) grade = "B+";
            else if (scoreIn100 >= 60) grade = "B";
            else if (scoreIn100 >= 55) grade = "B-";
            else if (scoreIn100 >= 50) grade = "C+";
            else if (scoreIn100 >= 45) grade = "C";
            else if (scoreIn100 >= 40) grade = "D";
            else grade = "F";

            return grade;
        }catch (InvalidNumberException error){
            System.out.println(error);
            return "-X";
        }
    }
}
