import java.util.Scanner;
import java.lang.Math;

public class T01_GavinTan_Lab2 {
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        Cylinder[] arr = new Cylinder[5];

        int counter = 0;
        while (counter < 5){
            System.out.println("Container Type: ");
            String type = myObj.nextLine();
            
            System.out.println("Radius : ");
            int radius= Integer.parseInt(myObj.nextLine());
    
            System.out.println("Height: ");
            int height = Integer.parseInt(myObj.nextLine());
            
            Cylinder container = new Cylinder(type,radius, height);
            container.getVolume();
            arr[counter] = container;
            counter++;
        }

        System.out.println("Container Search:");
        System.out.println("1 By type");
        System.out.println("2 By volume");
        System.out.println("3 Quit");
        System.out.println("Your selection?");
        
        String response = myObj.nextLine();
        switch(response) {
            case "1":
                System.out.println("Enter type: ");
                String inputType = myObj.nextLine();

                for (int count = 0; count < arr.length; count++) {
                    if (arr[count].type.equals(inputType)) System.out.println(arr[count]);
                }
                
                break;
            case "2":
                System.out.println("Enter volume: ");
                int inputVolume = Integer.parseInt(myObj.nextLine());

                for (int count = 0; count < arr.length; count++) {
                    if (arr[count].getVolume() > inputVolume) System.out.println(arr[count]);
                }

                break;
            default: // Quit
                break;
        }
    }
}

class Cylinder {
    public String type;
    public int radius, height, volume;
    
    public Cylinder(String containerType, int containerRadius, int containerheight) {
        type = containerType;
        radius = containerRadius;
        height = containerheight;
    }

    int getRadius () {
        return radius;
    }

    int getHeight () {
        return height;
    }

    int getVolume () {
        volume = (int) Math.round(Math.PI * radius * radius * height);
        return volume;
    }

    @Override
    public String toString () {
        return type + " container with volume " + volume;
    }
}
