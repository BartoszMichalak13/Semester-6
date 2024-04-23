// Define an interface requiring arithmetic by value operations method
public interface ByValueOperations<T> {
    void setValue(T gf);
    void decreseValue(T gf);
    void increseValue(T gf);
    void multiplyByValue(T gf);
    void divideByValue(T gf);
}
