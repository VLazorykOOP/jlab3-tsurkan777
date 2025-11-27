// Інтерфейс Series (прогресія)
interface Series {
    double getElement(int n);   // обчислення n-го члена
    double getSum(int n);       // сума перших n членів

    // метод за замовчуванням для виводу
    default void Show(int n) {
        System.out.println("n-й член (" + n + "): " + getElement(n));
        System.out.println("Сума перших " + n + " членів: " + getSum(n));
        System.out.println("---------------------------");
    }
}

// Клас арифметичної прогресії
class Linear implements Series {
    private double first;   // перший член
    private double difference;  // різниця

    public Linear(double first, double difference) {
        this.first = first;
        this.difference = difference;
    }

    @Override
    public double getElement(int n) {
        return first + (n - 1) * difference;  // a_n = a1 + (n-1)*d
    }

    @Override
    public double getSum(int n) {
        return n / 2.0 * (2 * first + (n - 1) * difference);  // S_n = n/2*(2a1+(n-1)d)
    }

    @Override
    public void Show(int n) {
        System.out.println("Арифметична прогресія:");
        System.out.println("Перший член: " + first);
        System.out.println("Різниця: " + difference);
        Series.super.Show(n);
    }
}

// Клас геометричної прогресії
class Exponential implements Series {
    private double first;   // перший член
    private double q;       // знаменник

    public Exponential(double first, double q) {
        this.first = first;
        this.q = q;
    }

    @Override
    public double getElement(int n) {
        return first * Math.pow(q, n - 1);  // a_n = a1 * q^(n-1)
    }

    @Override
    public double getSum(int n) {
        if (q == 1)
            return first * n;  // якщо q=1, сума просто n*a1
        return first * (1 - Math.pow(q, n)) / (1 - q);  // S_n = a1*(1-q^n)/(1-q)
    }

    @Override
    public void Show(int n) {
        System.out.println("Геометрична прогресія:");
        System.out.println("Перший член: " + first);
        System.out.println("Знаменник: " + q);
        Series.super.Show(n);
    }
}

// Головна програма
public class Main {
    public static void main(String[] args) {
        Series[] series = new Series[2];

        series[0] = new Linear(2, 3);       // арифметична прогресія
        series[1] = new Exponential(2, 2);  // геометрична прогресія

        int n = 5;

        for (Series s : series) {
            s.Show(n);
        }
    }
}
