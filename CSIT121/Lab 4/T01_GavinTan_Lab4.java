import java.util.Scanner;
import java.util.ArrayList;
import java.lang.Math;

public class T01_GavinTan_Lab4 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        float x, y;

        boolean run = true;
        while (run) {
             ArrayList<Point> arr = new ArrayList<Point>();

            for (int count = 1; count <= 3; count++) {
                System.out.println("X-Coordinate of Point " + count + ": ");
                x = Float.parseFloat(input.nextLine());
                
                System.out.println("Y-Coordinate of Point " + count + ": ");
                y = Float.parseFloat(input.nextLine());
    
                Point point = new Point(x, y);
                arr.add(point);
            }

            Triangle triangle = new Triangle(arr.get(0), arr.get(1), arr.get(2));
            triangle.getArea();
            System.out.println(triangle);

            System.out.println("Enter another record? (y/n)");
            String response = input.nextLine().toLowerCase();

            if (!response.equals("y")) run = false;
        }
    }
}

class Point {
    private float x, y;

    public Point(float xCoord, float yCoord) {
        this.x = xCoord;
        this.y = yCoord;
    }

    float getXCoord() {
        return this.x;
    }

    float getYCoord() {
        return this.y;
    }
    
    double getDistance(Point point) {
        double xAxisDistance = Math.pow(point.getXCoord() - this.x, 2);
        double yAxisDistance = Math.pow(point.getYCoord() - this.y, 2);

        return Math.sqrt((xAxisDistance + yAxisDistance));
    }

    @Override
    public String toString () {
        return "x-coordinate: " + x + " y-coordinate: " + y;
    }
}

class Triangle {
    Point p1, p2, p3;
    
    public Triangle(Point point1, Point point2, Point point3) {
        p1 = point1;
        p2 = point2;
        p3 = point3;
    }

    double getArea() {
        double a = p1.getDistance(p2);
        double b = p2.getDistance(p3);
        double c = p3.getDistance(p1);

        double s = (a + b + c) / 2;
        return Math.sqrt((s * (s-a) * (s-b) * (s-c)));

    }

    @Override
    public String toString () {
        return "This triangle has 3 points:" + "\n" + 
        "Point 1: " + p1 + "\n" +
        "Point 2: " + p2 + "\n" + 
        "Point 3: " + p3 + "\n" + 
        "Total Area: " + this.getArea();
    }
}