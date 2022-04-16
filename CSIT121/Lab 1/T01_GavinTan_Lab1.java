import java.util.Scanner;

public class T01_GavinTan_Lab1 {
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        System.out.println("Please enter employee Id:");
        String employeeId = myObj.nextLine();
        
        System.out.println("Please enter employee name:");
        String employeeName = myObj.nextLine();

        System.out.println("Please enter hours worked:");
        int hours = Integer.parseInt(myObj.nextLine());
        
        System.out.println("Please enter hourly rate:");
        float rate = Float.parseFloat(myObj.nextLine());
        
        WeeklyPay employee = new WeeklyPay(employeeId,employeeName,hours,rate);
        employee.getPay();
        System.out.println(employee.toString());
        
    }
}

class WeeklyPay {
    public String id, name;
    public int hours;
    public float rate, pay;
    
    public WeeklyPay (String employeeId, String employeeName, int hoursWorked, float payRate) {
        id = employeeId;
        name = employeeName;
        hours = hoursWorked;
        rate = payRate;
    }

    float getPay () {
        if (hours > 40) pay = (40 * rate) + ((hours - 40) * (rate * 2));
        else pay = (hours * rate);

        return pay;
    }
    
    @Override
    public String toString () {
        return id + " " + name + " $" + pay;
    }
}
