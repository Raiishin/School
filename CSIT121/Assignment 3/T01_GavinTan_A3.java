import java.util.Scanner;
import java.util.ArrayList;
import java.nio.file.Paths;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class QuotationApp extends JFrame implements ActionListener {
    private JTextField txCode, txQty, txPrice, txDiscount, txTotal;
    private JButton bnLoad, bnPrev, bnNext;
    private ArrayList<QuotationItem> items = new ArrayList<QuotationItem>();
    private int counter = 0;

    public void createUI() {
        this.setTitle("Quotation Management");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);

        Container uiPane = this.getContentPane();
        txCode = new JTextField();
        txQty = new JTextField();
        txPrice = new JTextField();
        txDiscount = new JTextField();
        txTotal = new JTextField();

        JLabel lbCode = new JLabel("Code");
        JLabel lbQty = new JLabel("Quantity");
        JLabel lbPrice = new JLabel("Price");
        JLabel lbDiscount = new JLabel("Discount");
        JLabel lbTotal = new JLabel("Total");

        Box txLayout = Box.createVerticalBox();

        Box txCodeLayout = Box.createHorizontalBox();
        txCodeLayout.add(lbCode);
        txCodeLayout.add(txCode);
        txLayout.add(txCodeLayout);

        Box txQtyLayout = Box.createHorizontalBox();
        txQtyLayout.add(lbQty);
        txQtyLayout.add(txQty);
        txLayout.add(txQtyLayout);

        Box txPriceLayout = Box.createHorizontalBox();
        txPriceLayout.add(lbPrice);
        txPriceLayout.add(txPrice);
        txLayout.add(txPriceLayout);

        Box txDiscountLayout = Box.createHorizontalBox();
        txDiscountLayout.add(lbDiscount);
        txDiscountLayout.add(txDiscount);
        txLayout.add(txDiscountLayout);

        Box txTotalLayout = Box.createHorizontalBox();
        txTotalLayout.add(lbTotal);
        txTotalLayout.add(txTotal);
        txLayout.add(txTotalLayout);

        uiPane.add(txLayout, BorderLayout.NORTH);

        bnLoad = new JButton("Load");
        bnPrev = new JButton("Prev");
        bnNext = new JButton("Next");

        Box bnLayout = Box.createHorizontalBox();
        bnLayout.add(bnLoad);
        bnLayout.add(bnPrev);
        bnLayout.add(bnNext);
        uiPane.add(bnLayout, BorderLayout.EAST);

        this.pack();
        bnLoad.addActionListener(this);
        bnPrev.addActionListener(this);
        bnNext.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent event) {
        String action = event.getActionCommand(); // Assign the action to a variable for ease of access

        if (action.equals("Load")) {
            String filename = "/Users/gavin/Desktop/School/CSIT121/Assignment 3/data.txt";

            try (Scanner file = new Scanner(Paths.get(filename))) { // To avoid wasting of resources
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

                // Fill up the textboxes with the first item in the arrayList
                QuotationItem item = items.get(counter);

                txCode.setText(item.getCode());
                txQty.setText(Integer.toString(item.getQuantity()));
                txPrice.setText(Float.toString(item.getPrice()));
                txDiscount.setText(Float.toString(item.getDiscount()));
                txTotal.setText(Float.toString(item.getTotal()));

            } catch (Exception e) {
                JOptionPane.showMessageDialog(null,
                        "No quotation record",
                        "Message",
                        JOptionPane.INFORMATION_MESSAGE);
            }
        }

        if (action.equals("Next")) {
            counter += 1;

            QuotationItem item = items.get(counter);

            txCode.setText(item.getCode());
            txQty.setText(Integer.toString(item.getQuantity()));
            txPrice.setText(Float.toString(item.getPrice()));
            txDiscount.setText(Float.toString(item.getDiscount()));
            txTotal.setText(Float.toString(item.getTotal()));
        }

        if (action.equals("Prev")) {
            counter -= 1;

            QuotationItem item = items.get(counter);

            txCode.setText(item.getCode());
            txQty.setText(Integer.toString(item.getQuantity()));
            txPrice.setText(Float.toString(item.getPrice()));
            txDiscount.setText(Float.toString(item.getDiscount()));
            txTotal.setText(Float.toString(item.getTotal()));
        }

        // Logic for checking if the user is on the first/last item of the arrayList
        if (counter == 0) {
            bnPrev.setEnabled(false);
        } else if (counter == items.size() - 1) {
            bnNext.setEnabled(false);
        } else {
            bnPrev.setEnabled(true);
            bnNext.setEnabled(true);
        }
    }
}

public class T01_GavinTan_A3 {
    public static void main(String[] args) {
        QuotationApp app = new QuotationApp();
        app.createUI();
        app.setVisible(true);
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