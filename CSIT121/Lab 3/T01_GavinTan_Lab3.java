import java.util.Scanner;
import java.util.ArrayList;

public class T01_GavinTan_Lab3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Parcel> arr = new ArrayList<Parcel>();

        Boolean isLongDistance = false;
        Boolean isExpress = false;

        boolean run = true;
        while (run){
            System.out.println("Parcel code: ");
            String code = input.nextLine().toUpperCase();
            
            System.out.println("Length: ");
            int length = Integer.parseInt(input.nextLine());

            System.out.println("Width: ");
            int width = Integer.parseInt(input.nextLine());

            System.out.println("Height: ");
            int height = Integer.parseInt(input.nextLine());

            System.out.println("Weight: ");
            float weight = Float.parseFloat(input.nextLine());

            System.out.println("Express (y/n)? ");
            String selection = input.nextLine().toLowerCase();

            if (selection.equals("y")) {
                isExpress = true;
                System.out.println("Long distance (y/n)? ");
                selection = input.nextLine().toLowerCase();

                if (selection.equals("y")) isLongDistance = true;
            }

            if (isExpress) {
                Parcel8 parcel = new Parcel8(code, length, width, height);
                parcel.setWeight(weight);
                if (isLongDistance) parcel.setLongDistance(isLongDistance);
                parcel.getVolume();
                parcel.getVolumetricWeight();
                parcel.getFee();

                arr.add(parcel);

            } else {
                Parcel parcel = new Parcel(code, length, width, height);
                parcel.setWeight(weight);
                parcel.getVolume();
                parcel.getVolumetricWeight();
                parcel.getFee();

                arr.add(parcel);
            }

            System.out.println("Enter another record? (y/n)");
            String response = input.nextLine().toLowerCase();

            if (response.equals("n")) run = false;
        }

        System.out.println("1 Show all items");
        System.out.println("2 Show express items");
        System.out.println("3 Quit");
        System.out.println("Your selection:");
        
        String response = input.nextLine();
        switch(response) {
            case "1":
                for (int count = 0; count < arr.size(); count++) System.out.println(arr.get(count));
                
                break;
            case "2":
                for (Parcel parcel: arr) {
                    if (parcel instanceof Parcel8) System.out.println(parcel);
                }

                break;
            default: // Quit
                break;
        }
    }
}

class Parcel {
    private String code;
    private int length, width, height;
    private float weight;
    
    public Parcel(String parcelCode, int parcelLength, int parcelWidth, int parcelHeight) {
        this.code = parcelCode;
        this.length = parcelLength;
        this.width = parcelWidth;
        this.height = parcelHeight;
    }

    String getCode () {
        return this.code;
    }

    int getLength () {
        return this.length;
    }

    int getWidth () {
        return this.width;
    }

    int getHeight () {
        return this.height;
    }

    public void setWeight (float weight) {
        this.weight = weight;
    }

    float getWeight () {
        return this.weight;
    }

    float getVolume () {
        return this.length * this.width * this.height;
    }

    float getVolumetricWeight () {
        return (float) this.getVolume() / 5000;
    }

    float getFee () {
        float finalWeight = this.weight;
        if (finalWeight < this.getVolumetricWeight()) finalWeight = this.getVolumetricWeight();

        float fee = 3;
        finalWeight -= 1;

        while (finalWeight > 0) {
            fee += 1;
            finalWeight -= 1;
        }

        return fee;
    }

    @Override
    public String toString () {
        return this.getCode() + " $" + this.getFee();
    }
}

class Parcel8 extends Parcel {
    private Boolean longDistance = false;

    public Parcel8(String parcelCode, int parcelLength, int parcelWidth, int parcelHeight) {
        super(parcelCode, parcelLength, parcelWidth, parcelHeight);
    }

    public void setLongDistance(Boolean isLongDistance) {
        this.longDistance = isLongDistance;
      }

    @Override
    float getFee() {
        float finalWeight = this.getWeight();
        if (finalWeight < this.getVolumetricWeight()) finalWeight = this.getVolumetricWeight();

        float fee = 3;
        finalWeight -= 1;

        while (finalWeight > 0) {
            fee += 1;
            finalWeight -= 1;
        }

        if (this.longDistance) fee = (float) (fee * 1.35);
        else fee = (float) (fee * 1.2);
        
        return fee;
    }

    @Override
    public String toString () {
        return "Express " + this.getCode() + " $" + this.getFee();
    }
}