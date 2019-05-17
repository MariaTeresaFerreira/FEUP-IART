import java.util.*;

public class Board {
    public static final int N_PLAYERS = 2;
    public static final int N_STONES = 4;
    public static final int N_PITS = 6;

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
        repeatTurn = false;

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

        for (int i = N_PITS - 1; i >= 0; i--){
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

    public boolean move(int side, int pit){
        repeatTurn = false;

        if (side != activePlayer)
            return false;

        if (pits[side][pit] == 0)
            return false;

        int rocks = pits[side][pit];
        pits[side][pit] = 0;

        while (rocks > 0){

            pit = nextPit(pit);

            if(pit == 0){

                if(side == activePlayer){
                    mancalas[side] += 1;
                    rocks -= 1;

                    if(rocks == 0){
                        checkEmpty();
                        repeatTurn = true;
                        return false;
                    }
                }
                side = nextSide(side);
            }
            pits[side][pit] += 1;
            rocks -= 1;
        }
        endTurn(side, pit);

        return true;
    }

    private int nextPit(int pit)
    {
        pit += 1;
        if (pit == N_PITS)
            pit = 0;
        return pit;
    }

    private int nextSide(int side)
    {
        side += 1;
        if (side == N_PLAYERS)
            side = 0;
        return side;
    }

    private void endGame(int side)
    {
        gameOver = true;

        for (int i = 0; i < N_PITS; i++) {
            mancalas[side] += pits[side][i];
            pits[side][i] = 0;
        }
    }

    private void checkEmpty() {

        int empty;
        for (int i = 0; i < N_PLAYERS; i++)
        {
            empty = 0;
            for (int j = 0; j < N_PITS; j++)
            {
                if (pits[i][j] == 0)
                    empty++;
            }

            if (empty == N_PITS)
            {
                endGame(nextSide(i));
                break;
            }
        }
    }

    private void endTurn(int side, int pit){

        if (side == activePlayer && pits[side][pit] == 1)
        {
            mancalas[side] += 1 + pits[nextSide(side)][N_PITS - pit - 1];
            pits[side][pit] = 0;
            pits[nextSide(side)][N_PITS - pit - 1] = 0;
            repeatTurn = true;
        }
        else
        {
            activePlayer = nextSide(activePlayer);
        }

        checkEmpty();
    }

}
