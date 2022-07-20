import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Question4 {
    public static void main(String[] args) {
        ShiftCipher myApp = new ShiftCipher();
        myApp.createUI();
        myApp.setVisible(true);
    }
}

class ShiftCipher extends JFrame implements ActionListener {
    private JTextField txShift, txMessage, txEncrypted, txDecrypted;
    private JButton bnSet, bnEncrypt, bnDecrypt, bnReset;
    private Boolean isShiftSet = false;
    private int shift = 0;

    public void createUI() {
        this.setTitle("Shift Cipher");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);

        Container uiPane = this.getContentPane();
        txShift = new JTextField();
        txMessage = new JTextField();
        txEncrypted = new JTextField();
        txDecrypted = new JTextField();

        JLabel lbShift = new JLabel("Shift");
        JLabel lbMessage = new JLabel("Message");
        JLabel lbEncrypted = new JLabel("Encrypted");
        JLabel lbDecrypted = new JLabel("Decrypted");

        bnSet = new JButton("Set");
        bnEncrypt = new JButton("Encrypt");
        bnDecrypt = new JButton("Decrypt");
        bnReset = new JButton("Reset");

        Box txLayout = Box.createVerticalBox();

        Box txShiftLayout = Box.createHorizontalBox();
        txShiftLayout.add(lbShift);
        txShiftLayout.add(txShift);
        txShiftLayout.add(bnSet);
        txLayout.add(txShiftLayout);

        Box txMessageLayout = Box.createHorizontalBox();
        txMessageLayout.add(lbMessage);
        txMessageLayout.add(txMessage);
        txMessageLayout.add(bnEncrypt);
        txLayout.add(txMessageLayout);

        Box txEncryptedLayout = Box.createHorizontalBox();
        txEncryptedLayout.add(lbEncrypted);
        txEncryptedLayout.add(txEncrypted);
        txEncryptedLayout.add(bnDecrypt);
        txLayout.add(txEncryptedLayout);

        Box txDecryptedLayout = Box.createHorizontalBox();
        txDecryptedLayout.add(lbDecrypted);
        txDecryptedLayout.add(txDecrypted);
        txDecryptedLayout.add(bnReset);
        txLayout.add(txDecryptedLayout);

        uiPane.add(txLayout, BorderLayout.NORTH);

        this.pack();
        bnSet.addActionListener(this);
        bnEncrypt.addActionListener(this);
        bnDecrypt.addActionListener(this);
        bnReset.addActionListener(this);
    }

    String messageToCipher(String message, int shift) {
        String cipherText = "";

        for (int i = 0; i < message.length(); i++) {
            char c = (char) (message.charAt(i) + shift);

            if (c > 'z')
                cipherText += (char) (message.charAt(i) - (26 - shift));
            else
                cipherText += (char) (message.charAt(i) + shift);
        }

        return cipherText;
    }

    String decipherMessage(String cipherText, int shift) {
        String message = "";

        for (int i = 0; i < message.length(); i++) {
            char c = (char) (message.charAt(i) - shift);

            if (c > 'a')
                message += (char) (message.charAt(i) + (26 + shift));
            else
                message += (char) (message.charAt(i) - shift);
        }

        return message;
    }

    @Override
    public void actionPerformed(ActionEvent event) {
        String action = event.getActionCommand();

        if (action.equals("Set")) {
            shift = Integer.parseInt(txShift.getText());

            if (shift <= 0 || shift >= 26) {
                JOptionPane.showMessageDialog(null,
                        "Shift value must be 1 to 25",
                        "",
                        JOptionPane.ERROR_MESSAGE);
                isShiftSet = false;
            } else {
                isShiftSet = true;
            }
        }

        if (isShiftSet) {
            if (action.equals("Encrypt")) {
                String message = txMessage.getText();
                String encrypted = messageToCipher(message, shift);

                txEncrypted.setText(encrypted);
            }

            if (action.equals("Decrypt")) {
                String cipherText = txEncrypted.getText();
                String deciphered = messageToCipher(cipherText, shift);

                txDecrypted.setText(deciphered);
            }
        }
    }

}
