import java.util.Scanner;
import java.util.ArrayList;
import java.nio.file.Paths;
import java.io.FileNotFoundException;

public class Question3 {
    public static boolean isValidNumber(String number) {
        Boolean response = false;
        if (number.matches("[+-]?([0-9]*[.])?[0-9]+"))
            response = true;

        return response;
    }

    public static void main(String[] args) {
        ArrayList<Rectangle> shapes = new ArrayList<Rectangle>();

        try {

            Scanner input = new Scanner(System.in);

            System.out.println("File path? ");
            String filename = input.nextLine();

            try (Scanner file = new Scanner(Paths.get(filename))) { // To avoid wasting of resources

                while (file.hasNext()) { // Checking for each line of data in the file
                    String line = file.next();
                    String[] splitLine = line.split(",");

                    String type = splitLine[0];

                    Float length, width;
                    Float height = (float) 0;
                    boolean isValid = true;

                    if (isValidNumber(splitLine[1]) && isValidNumber(splitLine[2])) {
                        length = Float.parseFloat(splitLine[1]);
                        width = Float.parseFloat(splitLine[2]);
                        if (length <= 0 && width <= 0)
                            isValid = false;

                        if (type.equalsIgnoreCase("C") || type.equalsIgnoreCase("P")) {
                            if (isValidNumber(splitLine[3])) {
                                height = Float.parseFloat(splitLine[3]);
                                if (height <= 0)
                                    isValid = false;
                            }
                        }

                        if (isValid) {
                            if (type.equalsIgnoreCase("R")) {
                                Rectangle r = new Rectangle(length, width);
                                shapes.add(r);
                            }

                            if (type.equalsIgnoreCase("C")) {
                                Cuboid c = new Cuboid(length, width, height);
                                shapes.add(c);
                            }

                            if (type.equalsIgnoreCase("P")) {
                                Pyramid p = new Pyramid(length, width, height);
                                shapes.add(p);
                            }
                        }
                    }
                }

                boolean run = true;
                while (run) {
                    System.out.println("1 Search by length");
                    System.out.println("2 Search by height");
                    System.out.println("3 Quit");
                    System.out.println("Your selection:");

                    String response = input.nextLine();
                    switch (response) {
                        case "1":
                            System.out.println("Input length");
                            String inputLength = input.nextLine();
                            Float length;

                            Boolean doesExist = false;

                            if (isValidNumber(inputLength)) {
                                length = Float.parseFloat(inputLength);

                                if (length > 0) {
                                    for (int i = 0; i < shapes.size(); i++) {
                                        if (shapes.get(i).getLength() >= length) {
                                            System.out.println(shapes.get(i));
                                            doesExist = true;
                                        }
                                    }
                                } else {
                                    System.out.println("Invalid Input");
                                }

                            } else
                                System.out.println("Invalid Input");

                            if (!doesExist) {
                                System.out
                                        .println("There are no shapes that has a length >= to the length you entered");
                            }
                            break;
                        case "2":
                            System.out.println("Input height");
                            String inputHeight = input.nextLine();
                            Float height;

                            doesExist = false;

                            if (isValidNumber(inputHeight)) {
                                height = Float.parseFloat(inputHeight);

                                if (height > 0) {
                                    for (Rectangle shape : shapes) {
                                        if (shape instanceof Pyramid) {
                                            if (((Pyramid) shape).getHeight() >= height) {
                                                System.out.println(shape);
                                                doesExist = true;
                                            }
                                        }

                                        if (shape instanceof Cuboid) {
                                            if (((Cuboid) shape).getHeight() >= height) {
                                                System.out.println(shape);
                                                doesExist = true;
                                            }
                                        }
                                    }

                                } else {
                                    System.out.println("Invalid Input");
                                }

                            } else
                                System.out.println("Invalid Input");

                            if (!doesExist) {
                                System.out
                                        .println("There are no shapes that has a length >= to the length you entered");
                            }
                            break;
                        default: // Save and Quit
                            run = false;
                            break;
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

class Rectangle {
    private float length, width;

    public Rectangle(float length, float width) {
        this.length = length;
        this.width = width;
    }

    float getLength() {
        return this.length;
    }

    float getWidth() {
        return this.width;
    }

    void setLength(float length) {
        this.length = length;
    }

    void setWidth(float width) {
        this.width = width;
    }

    float getArea() {
        return this.length * this.width;
    }

    @Override
    public String toString() {
        return "Rectange with a length of " + this.getLength() + " and a width of " + this.getWidth()
                + " has an area of " + this.getArea();
    }
}

class Cuboid extends Rectangle {
    private float height;

    public Cuboid(float length, float width, float height) {
        super(length, width);
        this.height = height;
    }

    float getHeight() {
        return this.height;
    }

    void setHeight(float height) {
        this.height = height;
    }

    @Override
    float getArea() {
        float surfaceArea = 2 * (this.getLength() * this.getWidth()) + 2 * (this.getLength() * this.height)
                + 2 * (this.getWidth() + this.height);
        return surfaceArea;
    }

    float getVolume() {
        float volume = this.getLength() * this.getWidth() * this.height;
        return volume;
    }

    @Override
    public String toString() {
        return "Cuboid with a length of " + this.getLength() + " and a width of " + this.getWidth()
                + " and a height of " + this.height
                + " has a surface area of " + this.getArea() + " and a volume of " + this.getVolume();
    }
}

class Pyramid extends Rectangle {
    private float height;

    public Pyramid(float length, float width, float height) {
        super(length, width);
        this.height = height;
    }

    float getHeight() {
        return this.height;
    }

    void setHeight(float height) {
        this.height = height;
    }

    float getVolume() {
        float volume = (this.getLength() * this.getWidth() * this.height) / 3;
        return volume;
    }

    @Override
    public String toString() {
        return "Pyramid with a length of " + this.getLength() + " and a width of " + this.getWidth()
                + " and a height of " + this.height
                + " has a volume of " + this.getVolume();
    }
}