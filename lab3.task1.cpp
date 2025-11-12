
class Transport {
    protected String name;
    protected int capacity;

    public Transport(String name, int capacity) {
        this.name = name;
        this.capacity = capacity;
    }

    public void Show() {
        System.out.println("Назва: " + name);
        System.out.println("Місткість: " + capacity);
    }
}

 
class Car extends Transport {
    private String fuelType;

    public Car(String name, int capacity, String fuelType) {
        super(name, capacity);
        this.fuelType = fuelType;
    }

    @Override
    public void Show() {
        super.Show();
        System.out.println("Тип палива: " + fuelType);
        System.out.println("---------------------------");
    }
}


class Train extends Transport {
    private int numberOfCars;

    public Train(String name, int capacity, int numberOfCars) {
        super(name, capacity);
        this.numberOfCars = numberOfCars;
    }

    @Override
    public void Show() {
        super.Show();
        System.out.println("Кількість вагонів: " + numberOfCars);
        System.out.println("---------------------------");
    }
}

class Express extends Train {
    private int maxSpeed;

    public Express(String name, int capacity, int numberOfCars, int maxSpeed) {
        super(name, capacity, numberOfCars);
        this.maxSpeed = maxSpeed;
    }

    @Override
    public void Show() {
        super.Show();
        System.out.println("Максимальна швидкість: " + maxSpeed + " км/год");
        System.out.println("---------------------------");
    }
}


public class Main {
    public static void main(String[] args) {
        
        Transport[] transports = new Transport[3];

        
        transports[0] = new Car("Toyota Corolla", 5, "Бензин");
        transports[1] = new Train("Passenger Train", 200, 10);
        transports[2] = new Express("High-Speed Express", 300, 8, 250);

        
        for (Transport t : transports) {
            t.Show();
        }
    }
}
