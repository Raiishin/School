import java.util.ArrayList;
import java.util.Scanner;

public class T01_GavinTan_A2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<ToyCar> toyCarArr = new ArrayList<ToyCar>();
        ArrayList<ToyCarElect> toyCarElectArr = new ArrayList<ToyCarElect>();

        boolean run = true;

        while (run) {
            System.out.println("1 Add inventory");
            System.out.println("2 Remove inventory");
            System.out.println("3 Show all inventory");
            System.out.println("4 Search inventory by car model");
            System.out.println("5 Search inventory by car price");
            System.out.println("6 Search inventory by car battery duration");
            System.out.println("7 Quit");
            System.out.println("Your selection?");
    
            String response = input.nextLine();
            String modelCode = "";

            boolean isPresent = false;

            switch(response) {
                case "1":
                    System.out.println("Enter Model Code: ");
                    modelCode = input.nextLine().toUpperCase();
    
                    for (int count = 0; count < toyCarArr.size(); count++) {
                        if (toyCarArr.get(count).code.equals(modelCode)) {
                            isPresent = true;
                            System.out.println("This model is already in the inventory");
                        }
                    }
    
                    if (!isPresent) {
                        System.out.println("Enter Price: ");
                        float price = Float.parseFloat(input.nextLine());
                        if (price <= 0) {
                            System.out.println("Invalid Price");
                            break;
                        }
    
                        System.out.println("Enter Quantity: ");
                        int quantity = Integer.parseInt(input.nextLine());
                        if (quantity < 0) {
                            System.out.println("Invalid Quantity");
                            break;
                        }
    
                        System.out.println("Is the Car Battery-powered (y/n)?: ");
                        String electric = input.nextLine().toLowerCase();
                        if (electric.equals("y")) {
    
                            System.out.println("Enter Battery Duration (minutes): ");
                            int batteryDuration = Integer.parseInt(input.nextLine());
                            if (batteryDuration <= 0) {
                                System.out.println("Invalid Battery Duration");
                                break;
                            }
    
                            System.out.println("Enter Charging Duration (minutes): ");
                            int ChargingDuration = Integer.parseInt(input.nextLine());
                            if (ChargingDuration <= 0) {
                                System.out.println("Invalid Charging Duration");
                                break;
                            }
                            
                            ToyCarElect car = new ToyCarElect(modelCode, quantity, price,batteryDuration,ChargingDuration);
                            car.getTotalInventoryWorth();
                            car.getInsuranceCost();
                            toyCarElectArr.add(car);
                        } else {
                            ToyCar car = new ToyCar(modelCode, quantity, price);
                            car.getTotalInventoryWorth();
                            car.getInsuranceCost();
                            toyCarArr.add(car);
                        }
                    }
    
                    break;
                case "2":
                    System.out.println("Enter Model Code: ");
                    modelCode = input.nextLine().toUpperCase();
    
                    for (int count = 0; count < toyCarArr.size(); count++) {
                        if (toyCarArr.get(count).code.equals(modelCode)) {
                            isPresent = true;
    
                            if (toyCarArr.get(count).quantity > 0) System.out.println("There is " + toyCarArr.get(count).quantity + " more left in the inventory");
                            else toyCarArr.remove(count);
                        }
                    }

                    for (int count = 0; count < toyCarElectArr.size(); count++) {
                        if (toyCarElectArr.get(count).code.equals(modelCode)) {
                            isPresent = true;
    
                            if (toyCarElectArr.get(count).quantity > 0) System.out.println("There is " + toyCarElectArr.get(count).quantity + " more left in the inventory");
                            else toyCarElectArr.remove(count);
                        }
                    }
    
                    if (!isPresent) System.out.println("This model does not exist in the inventory");
    
                    break;
                case "3":
                    for (int count = 0; count < toyCarArr.size(); count++) System.out.println(toyCarArr.get(count));
                    for (int count = 0; count < toyCarElectArr.size(); count++) System.out.println(toyCarElectArr.get(count));
    
                    break;
                case "4":
                    System.out.println("Enter Model Code: ");
                    modelCode = input.nextLine().toUpperCase();
    
                    for (int count = 0; count < toyCarArr.size(); count++) {
                        if (toyCarArr.get(count).code.equals(modelCode)) {
                            isPresent = true;
                            System.out.println(toyCarArr.get(count));
                        }
                    }
    
                    for (int count = 0; count < toyCarElectArr.size(); count++) {
                        if (toyCarElectArr.get(count).code.equals(modelCode)) {
                            isPresent = true;
                            System.out.println(toyCarElectArr.get(count));
                        }
                    }

                    if (!isPresent) System.out.println("This model does not exist in the inventory");

                    break;
                case "5":
                    System.out.println("Enter Lower Bound: ");
                    float lowerBound = Float.parseFloat(input.nextLine());
    
                    System.out.println("Enter Upper Bound: ");
                    float upperBound = Float.parseFloat(input.nextLine());
    
                    for (int count = 0; count < toyCarArr.size(); count++) {
                        if (toyCarArr.get(count).price >= lowerBound && toyCarArr.get(count).price <= upperBound) {
                            isPresent = true;
                            System.out.println(toyCarArr.get(count));
                        }
                    }
    
                    for (int count = 0; count < toyCarElectArr.size(); count++) {
                        if (toyCarElectArr.get(count).price >= lowerBound && toyCarElectArr.get(count).price <= upperBound) {
                            isPresent = true;
                            System.out.println(toyCarElectArr.get(count));
                        }
                    }

                    if (!isPresent) System.out.println("There are no models that have a price within the specific range");
    
                    break;
                case "6":
                    System.out.println("Enter Battery Duration (minutes): ");
                    float batteryDuration = Float.parseFloat(input.nextLine());
    
                    for (int count = 0; count < toyCarElectArr.size(); count++) {
                        if (toyCarElectArr.get(count).batteryDuration >= batteryDuration) {
                            isPresent = true;
                            System.out.println(toyCarElectArr.get(count));
                        }
                    }
    
                    if (!isPresent) System.out.println("There are no models that have a battery duration longer than the specified value");
    
                    break;
                default: // Quit
                    run = false;
                    break;
            }
        }
    }
}

class ToyCar {
    String code;
    int quantity;
    float price, totalInventoryWorth;

    public ToyCar(String carCode, int carQuantity, float carPrice) {
        code = carCode;
        quantity = carQuantity;
        price = carPrice;
    }

    float getTotalInventoryWorth () {
        totalInventoryWorth = (float) price * quantity;
        return totalInventoryWorth;
    }

    float getInsuranceCost () {
        return (float) 0.02 * totalInventoryWorth;
    }

    @Override
    public String toString () {
        return "Model: " + code + " (Self pedaling) Price: $" + price + " Quantity: " + quantity;
    }
}

class ToyCarElect extends ToyCar {
    protected int batteryDuration, chargingDuration;

    public ToyCarElect(String carCode, int carQuantity, float carPrice, int battery, int charging) {
        super(carCode, carQuantity, carPrice);
        batteryDuration = battery;
        chargingDuration = charging;
    }

    @Override
    float getInsuranceCost () {
        return (float) 0.1 * totalInventoryWorth;
    }

    @Override
    public String toString () {
        return "Model: " + code + " (Battery-powered) Price: $" + price + " Quantity: " + quantity;
    }
}