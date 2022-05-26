import java.util.Scanner;
import java.util.ArrayList;
import java.nio.file.Paths;
import java.io.FileWriter;
import java.io.FileNotFoundException;

public class T01_GavinTan_Lab5 {
    public static void main(String[] args) {
        try {
            Scanner input = new Scanner(System.in);

            System.out.println("File path? "); // User will input the designated file path
            String filename = input.nextLine();

            try (Scanner file = new Scanner(Paths.get(filename))) { // To avoid wasting of resources
                ArrayList<QuotationItem> items = new ArrayList<QuotationItem>();

                while (file.hasNext()) { // Checking for each line of data in the file
                    String line = file.next();
                    String[] splitLine = line.split(",");

                    String code = splitLine[0];
                    Integer quantity = Integer.parseInt(splitLine[1]);
                    Float price = Float.parseFloat(splitLine[2]);
                    Float discount = Float.parseFloat(splitLine[3]);

                    if (quantity > 0 && price > 0) { // The program will ignore (skip) erroneous lines in the file
                        QuotationItem item = new QuotationItem(code, quantity, price, discount);
                        items.add(item);
                    }
                }

                boolean run = true;
                while (run) {
                    System.out.println("1 Adjust price and discount");
                    System.out.println("2 Show all items");
                    System.out.println("3 Save and Quit");
                    System.out.println("Your selection:");

                    String response = input.nextLine();
                    switch (response) {
                        case "1":
                            Boolean isCompleted = false;
                            Boolean doesExist = false;
                            int count = 0;

                            // To allow the user to repeat this action if code does not exist or is invalid
                            while (!isCompleted) {
                                System.out.println("Product Code:");
                                String inputCode = input.nextLine();
                                for (int i = 0; i < items.size(); i++) {
                                    if (inputCode.equals(items.get(i).getCode())) {
                                        doesExist = true;
                                        count = i;
                                    }
                                }
                                if (doesExist) {
                                    System.out.println("Please key in the updated price: ");
                                    Float changedPrice = Float.parseFloat(input.nextLine());
                                    items.get(count).setPrice(changedPrice);

                                    System.out.println("Please key in the updated discount if any: ");
                                    Float changedDiscount = Float.parseFloat(input.nextLine());
                                    items.get(count).setDiscount(changedDiscount);

                                    isCompleted = true;
                                } else
                                    System.out.println("No such product code exists!"); // Error handling

                            }

                            System.out.println("Prices have been adjusted accordingly!");
                            break;
                        case "2":
                            for (int i = 0; i < items.size(); i++)
                                System.out.println(items.get(i));

                            break;
                        default: // Save and Quit
                            run = false;
                            try {
                                // User will input the designated file path
                                System.out.println("Enter file path to save the updated file: ");
                                String updatedFilePath = input.nextLine();
                                FileWriter myWriter = new FileWriter(updatedFilePath);

                                for (int i = 0; i < items.size(); i++) {
                                    QuotationItem item = items.get(i);

                                    myWriter.write(item.getCode() + "," +
                                            item.getQuantity() + "," +
                                            item.getPrice() + "," + item.getDiscount() + "," + item.getTotal()
                                            + "\n");

                                }

                                myWriter.close();
                                break;
                            } catch (Exception e) {
                                System.out.println(e);
                            }
                    }
                }
            } catch (FileNotFoundException e) {
                System.out.println(e);
            }

            input.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

class QuotationItem {
    private String code;
    private int quantity;
    private float price, discount, total;

    public QuotationItem(String code, int quantity, float price, float discount) {
        this.code = code;
        this.quantity = quantity;
        this.price = price;
        this.discount = discount;
    }

    String getCode() {
        return this.code;
    }

    int getQuantity() {
        return this.quantity;
    }

    float getPrice() {
        return this.price;
    }

    void setPrice(float price) {
        this.price = price;
    }

    float getDiscount() {
        return this.discount;
    }

    void setDiscount(float discount) {
        this.discount = discount;
    }

    float getTotal() {
        this.total = (this.getQuantity() * this.getPrice()) * (1 - this.getDiscount());
        return this.total;
    }

    @Override
    public String toString() {
        return "Code: " + this.getCode() + " Quantity: " + this.getQuantity() + " Price: " + this.getPrice()
                + " Discount: " + this.getDiscount() + " Total: " + this.getTotal();
    }
}

// Input File:
// p1,10,50.5,0
// p2,50,70.5,0.1
// p3,10,0,0
// p4,30,10.0,0.05

// Output File:
// p1,10,20.0,0.1,180.0
// p2,50,30.0,0.1,1350.0
// p4,30,10.0,0.05,285.0
