package lb2;
import java.util.concurrent.Semaphore;

class Scribe implements Runnable {
    private static int scribeCount = 1;
    private static int penCount;
    private static int bottleCount;
    private static Semaphore penSemaphore;
    private static Semaphore bottleSemaphore;
    private int scribeId;

    public Scribe() {
        scribeId = scribeCount++;
    }

    @Override
    public void run() {
        while (true) {
            try {
                acquireResources();
                writeRecord();
                releaseResources();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return;
            }
        }
    }

    private void acquireResources() throws InterruptedException {
        bottleSemaphore.acquire();
        System.out.println("Scribe " + scribeId + " takes a bottle");
        penSemaphore.acquire();
        System.out.println("Scribe " + scribeId + " takes a pen");
    }

    private void writeRecord() throws InterruptedException {
        System.out.println("Scribe " + scribeId + " writes a record");
        Thread.sleep(1000); // Simulating the time it takes to write a record
    }

    private void releaseResources() {
        penSemaphore.release();
        System.out.println("Scribe " + scribeId + " puts the pen back");
        bottleSemaphore.release();
        System.out.println("Scribe " + scribeId + " puts the bottle back");
    }

    public static void main(String[] args) {
        if (args.length < 3) {
            System.out.println("Usage: java YourProgramName <number of scribes> <number of pens> <number of bottles>");
            return;
        }

        int numScribes = Integer.parseInt(args[0]);
        penCount = Integer.parseInt(args[1]);
        bottleCount = Integer.parseInt(args[2]);

        penSemaphore = new Semaphore(penCount, true);
        bottleSemaphore = new Semaphore(bottleCount, true);

        for (int i = 0; i < numScribes; i++) {
            Thread scribeThread = new Thread(new Scribe());
            scribeThread.start();
        }
    }
}

