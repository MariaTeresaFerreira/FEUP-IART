import java.util.*;

public class Board {
    public static final int N_PLAYERS = 2;
    public static final int N_PITS = 6;
    public static final int N_STONES = 4;


    private int[] mancalas;
    private int[][] pits;
    private int activePlayer;
    private Boolean repeatTurn;
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

    public void move(int side, int pit){

        if (side != activePlayer)
            return;

        if (pits[side][pit] == 0)
            return;

        int rocks = pits[side][pit];
        pits[side][pit] = 0;

        while (rocks > 0){

            pit = nextPit(pit);

            if(pit == 0){

                if(side == activePlayer){
                    mancalas[side]++;
                    rocks--;

                    if(rocks == 0){
                        //check if side empty
                        repeatTurn = true;
                        return;
                    }
                }

                side = nextSide(side);
            }

            pits[side][pit]++;
            rocks--;
        }
        //Change side
    }

    private int nextPit(int pit)
    {
        if (pit++ >= N_PITS)
            pit = 0;
        return pit;
    }

    private int nextSide(int side)
    {
        if (side++ >= N_PLAYERS)
            side = 0;
        return side;
    }



}
