import java.util.Random;
// Define a class representing DHSetup
class DHSetup<T extends IsGFlike<T>> {
    private final T generator;
    private final long p;

    public DHSetup(T a) {
        this.p = a.getP();
        this.generator = findGenerator(a);
    }

    private T findGenerator(T gf) {
        Random random = new Random();
        // T candidate = gf.screateInstanceetValue(random.nextInt((int) (p - 1)) + 1);
        gf.setValueByValue(random.nextInt((int) (p - 1)) + 1);
        T candidate = gf;

        while (!checkGenerator(candidate)) {
            // candidate = gf.createInstance(random.nextInt((int) (p - 1)) + 1);
            gf.setValueByValue(random.nextInt((int) (p - 1)) + 1);
            candidate = gf;
        }

        return candidate;
    }

    private boolean checkGenerator(T candidate) {
        for (long i = 2; i <= p - 1; i++) {
            if ((candidate.getValue() * (p - 1) / i) == 1) {
                return false;
            }
        }
        return true;
    }

    public long getP() {
        return p;
    }

    public T getGenerator() {
        return generator;
    }

    public static <T extends IsGFlike<T>> T power(T a, long b) {
        if (b == 1) {
            return a;
        }
        if ((b % 2) == 0) {
            if (b == 0) {
                // return a.createInstance(1); // Handle b == 0
                a.setValueByValue(1);
                return a; // Handle b == 0
            }
            T tmpA = a.multiply(a);
            return power(tmpA, b / 2);
        } else {
            T tmpA = a.multiply(a);
            T tmpA2 = power(tmpA, (b - 1) / 2);
            return tmpA2.multiply(a); // GF * GF should already have modulo operation
        }
    }
}