
import java.util.Random;
// Define a class representing User
class User<T extends IsGFlike<T>> {
    private T secret;
    private T key;
    private T generator;

    public User(DHSetup<T> dhs, T fieldElem) {
        this.secret = createSecret(dhs.getP(), fieldElem);
        this.generator = dhs.getGenerator();
        this.key = createKey(dhs, generator);
    }

    private T createSecret(long p, T fieldElem) {
        Random random = new Random();
        fieldElem.setValueByValue(random.nextInt((int) (p - 1)) + 1);
        return fieldElem;
    }

    private T createKey(DHSetup<T> dhs, T generator) {
        return DHSetup.power(generator, secret.getValue());
    }

    public T getPublicKey() {
        return generator;
    }

    public void setKey(T a) {
        this.key.setValue(DHSetup.power(a, secret.getValue()));
    }

    public T encrypt(T m) {
        if (key == null) {
            throw new IllegalStateException("Key not set");
        }
        return m.multiply(key);
    }

    public T decrypt(T c) {
        if (key == null) {
            throw new IllegalStateException("Key not set");
        }
        return c.divide(key);
    }
}