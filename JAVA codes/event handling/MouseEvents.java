import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class KeyBoardEvents extends JFrame implements KeyListener {
    JTextArea textArea;

    public KeyBoardEvents() {
        textArea = new JTextArea();
        add(textArea);
        textArea.addKeyListener(this);
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void keyPressed(KeyEvent e) {
        textArea.setText("Key Pressed: " + e.getKeyChar());
    }

    public void keyReleased(KeyEvent e) {
        textArea.setText("Key Released: " + e.getKeyChar());
    }

    public void keyTyped(KeyEvent e) {
        textArea.setText("Key Typed: " + e.getKeyChar());
    }

    public static void main(String[] args) {
        new KeyBoardEvents();
    }
}

class MouseEvents extends JFrame implements MouseListener, MouseMotionListener {
    JTextArea textArea;

    public MouseEvents() {
        textArea = new JTextArea();
        add(textArea);
        textArea.addMouseListener(this);
        textArea.addMouseMotionListener(this);
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void mouseClicked(MouseEvent e) {
        textArea.setText("Mouse Clicked at X: " + e.getX() + " Y: " + e.getY());
    }

    public void mouseEntered(MouseEvent e) {
        textArea.setText("Mouse Entered");
    }

    public void mouseExited(MouseEvent e) {
        textArea.setText("Mouse Exited");
    }

    public void mousePressed(MouseEvent e) {
        textArea.setText("Mouse Pressed");
    }

    public void mouseReleased(MouseEvent e) {
        textArea.setText("Mouse Released");
    }

    public void mouseDragged(MouseEvent e) {
        textArea.setText("Mouse Dragged at X: " + e.getX() + " Y: " + e.getY());
    }

    public void mouseMoved(MouseEvent e) {
        textArea.setText("Mouse Moved at X: " + e.getX() + " Y: " + e.getY());
    }

    public static void main(String[] args) {
        new MouseEvents();
    }
}
