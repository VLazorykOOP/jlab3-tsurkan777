abstract class Series {
    protected double first;   // перший член
    protected double ratio;   // різниця або знаменник прогресії

    public Series(double first, double ratio) {
        this.first = first;
        this.ratio = ratio;
    }

    // Абстрактні методи
    public abstract double getElement(int n);   // обчислення n-го члена
    public abstract double getSum(int n);       // сума перших n членів

    // Метод для виведення інформації
    public void Show(int n) {
        System.out.println("Перший член: " + first);
        System.out.println("Різниця / знаменник: " + ratio);
        System.out.println("n-й член (" + n + "): " + getElement(n));
        System.out.println("Сума перших " + n + " членів: " + getSum(n));
        System.out.println("---------------------------");
    }
}

// Підклас - арифметична прогресія
class Linear extends Series {

    public Linear(double first, double difference) {
        super(first, difference);
    }

    @Override
    public double getElement(int n) {
        return first + (n - 1) * ratio;  // a_n = a1 + (n-1)*d
    }

    @Override
    public double getSum(int n) {
        return n / 2.0 * (2 * first + (n - 1) * ratio);  // S_n = n/2 * (2a1 + (n-1)d)
    }
}

// Підклас - геометрична прогресія
class Exponential extends Series {

    public Exponential(double first, double q) {
        super(first, q);
    }

    @Override
    public double getElement(int n) {
        return first * Math.pow(ratio, n - 1);  // a_n = a1 * q^(n-1)
    }

    @Override
    public double getSum(int n) {
        if (ratio == 1) {
            return first * n;  // якщо q=1, сума просто n*a1
        }
        return first * (1 - Math.pow(ratio, n)) / (1 - ratio);  // S_n = a1*(1-q^n)/(1-q)
    }
}

// Головна програма
public class Main {
    public static void main(String[] args) {
        Series[] series = new Series[2];

        // Створюємо об’єкти прогресій
        series[0] = new Linear(2, 3);       // арифметична прогресія: 2, 5, 8, 11, ...
        series[1] = new Exponential(2, 2);  // геометрична прогресія: 2, 4, 8, 16, ...

        // Кількість членів
        int n = 5;

        // Вивід інформації
        for (Series s : series) {
            s.Show(n);
        }
    }
}

