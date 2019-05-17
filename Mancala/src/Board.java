import java.util.*;

public class Board {
    public static final int N_PLAYERS = 2;
    public static final int N_PITS = 6;
    public static final int N_STONES = 4;


    private int[] mancalas;
    private int[][] pits;
    private int activePlayer;
    private Boolean gameOver;


    public Board(){
        pits = new int[N_PLAYERS][N_PITS];
        mancalas = new int[N_PLAYERS];
        activePlayer = 0;
        gameOver = false;

        for (int p = 0; p < N_PLAYERS; p++)
        {
            mancalas[p] = 0;

            for (int col = 0; col < N_PITS; col++)
                pits[p][col] = N_STONES;
        }
    }

    public int[] getMancalas() {
        return mancalas;
    }

    public int[][] getPits() {
        return pits;
    }

    public int getActivePlayer() {
        return activePlayer;
    }

    public Boolean getGameOver() {
        return gameOver;
    }

    public void setMancalas(int[] mancalas) {
        this.mancalas = mancalas;
    }

    public void setPits(int[][] pits) {
        this.pits = pits;
    }

    public void setActivePlayer(int activePlayer) {
        this.activePlayer = activePlayer;
    }

    public void setGameOver(Boolean gameOver) {
        this.gameOver = gameOver;
    }

    public void draw(){

        System.out.println();

        for (int i = 0; i < N_PITS; i++){
            System.out.print("  ");
            System.out.print(pits[0][i]);
        }

        System.out.println();

        for (int i = 0; i < N_PLAYERS; i++){
            System.out.print(mancalas[i]);
            System.out.print("                  ");
        }

        System.out.println();

        for (int i = 0; i < N_PITS; i++){
            System.out.print("  ");
            System.out.print(pits[1][i]);
        }

        System.out.println();

    }
/*
    public boolean moveFinished(int player, int column){

        if(player == 1){
            int rocks = housesUp.get(column).getScore();
            housesUp.get(column).setScore(0);
            move(1,column, rocks);
        }
        else if( player == 2){
            int rocks = housesDown.get(column).getScore();
            housesDown.get(column).setScore(0);
            move(2,column, rocks);
        }
        return false;

    }

    private int move(int player, int column, int rocks){
        int finalPos = 0;
        for(int i = rocks; i > 0; i--){

        }
        return finalPos;
    }

    private void addRock(int player, int column){
        if(player == 1){
            housesUp.get(column).setScore(housesUp.get(column).getScore()+1);
        }
        else if( player == 2){
            housesDown.get(column).setScore(housesDown.get(column).getScore()+1);        }
    }
/*
    private int incrementPos(int line, int column){
        if(line == 2 && column == 6){
            return 16;
        }
        else if(line == 1 && column == 1){
            return 21;
        }

    }
*/

}
