import java.util.Scanner;
import java.util.ArrayList;

public class T01_GavinTan_Lab3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Parcel> arr = new ArrayList<Parcel>();

        String longDistance = "";

        boolean run = true;
        while (run){
            System.out.println("Parcel code: ");
            String code = input.nextLine();
            
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
                code = "Express " + code;
                System.out.println("Long distance (y/n)? ");
                longDistance = input.nextLine().toLowerCase();
            }

            if (longDistance.equals("y")) {
                Parcel8 parcel = new Parcel8(true, code, length, width, height, weight);
                parcel.getVolume();
                parcel.getVolumetricWeight();
                parcel.getFee();

                arr.add(parcel);

            } else {
                Parcel parcel = new Parcel(code, length, width, height,weight);
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
                for (int count = 0; count < arr.size(); count++) {
                    if (arr.get(count).getCode().contains("Express")) System.out.println(arr.get(count));
                }

                break;
            default: // Quit
                break;
        }
    }
}

class Parcel {
    public String code;
    public int length, width, height, volume;
    public float weight, volumentricWeight, fee;
    
    public Parcel(String parcelCode, int parcelLength, int parcelWidth, int parcelHeight, float parcelWeight) {
        code = parcelCode;
        length = parcelLength;
        width = parcelWidth;
        height = parcelHeight;
        weight = parcelWeight;
    }

    String getCode () {
        return code;
    }

    int getLength () {
        return length;
    }

    int getWidth () {
        return width;
    }

    int getHeight () {
        return height;
    }

    int getVolume () {
        volume = length * width * height;
        return volume;
    }

    float getVolumetricWeight () {
        volumentricWeight = (float) volume / 5000;
        return volumentricWeight;
    }

    float getFee () {
        float finalWeight = weight;
        if (weight < volumentricWeight) finalWeight = volumentricWeight;

        fee = 3;
        finalWeight -= 1;

        while (finalWeight > 0) {
            fee += 1;
            finalWeight -= 1;
        }

        if (code.contains("Express")) fee += (fee * 0.2);

        return fee;
    }

    @Override
    public String toString () {
        return code + " $" + fee;
    }
}

class Parcel8 extends Parcel {
    public Boolean longDistance;

    public Parcel8(Boolean isLongDistance, String parcelCode, int parcelLength, int parcelWidth, int parcelHeight, float parcelWeight) {
        super(parcelCode, parcelLength, parcelWidth, parcelHeight, parcelWeight);
        longDistance = isLongDistance;
    }

    @Override
    float getFee() {
        float finalWeight = weight;
        if (weight < volumentricWeight) finalWeight = volumentricWeight;

        fee = 3;
        finalWeight -= 1;

        while (finalWeight > 0) {
            fee += 1;
            finalWeight -= 1;
        }

        if (code.contains("Express")) fee += (fee * 0.35);

        return fee;
    }

    @Override
    public String toString () {
        return code + " $" + fee;
    }
}