import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args)throws IOException {

        while(true) {
            Scanner in = new Scanner(System.in);
            String modeInput;
            int mode = -1;


            while (true) {
                System.out.println("Insert the mode of the game you want to play:");
                System.out.println("1 for Human vs Human");
                System.out.println("2 for Human vs AI");
                System.out.println("3 for AI vs AI");
                modeInput = in.next();
                if (modeInput.equals("1") || modeInput.equals("2") || modeInput.equals("3"))
                    break;
                else
                    System.out.println("Please enter a valid option");
            }

            mode = Integer.parseInt(modeInput);

            if (mode != 1) {
                while (true) {
                    System.out.println("Insert AI difficulty:");
                    System.out.println("1 for Easy");
                    System.out.println("2 for Medium");
                    System.out.println("3 for Hard");
                    modeInput = in.next();
                    if (modeInput.equals("1")) {
                        Minimax.depthMax = 2;
                        break;
                    } else if (modeInput.equals("2")) {
                        Minimax.depthMax = 5;
                        break;
                    } else if (modeInput.equals("3")) {
                        Minimax.depthMax = 8;
                        break;
                    } else
                        System.out.println("Please enter a valid option");
                }
                mode = Integer.parseInt(modeInput);

                while (true) {
                    System.out.println("Do you want Minimax with alpha beta pruning?: (y/n)");
                    modeInput = in.next();
                    if (modeInput.equals("y")) {
                        Minimax.alphaBeta = true;
                        break;
                    } else if (modeInput.equals("n")) {
                        Minimax.alphaBeta = false;
                        break;
                    } else
                        System.out.println("Please enter a valid option");
                }

            }

            Game game = new Game();
            game.run(mode);

            while (true) {
                System.out.println("exit?: (y/n)");
                modeInput = in.next();
                if (modeInput.equals("y")) {
                    return;
                } else if (modeInput.equals("n")) {
                    break;
                } else
                    System.out.println("Please enter a valid option");
            }



        }

    }
}
