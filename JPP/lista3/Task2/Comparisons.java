// Define an interface requiring arithmetic comaprisions method
public interface Comparisons<T> {
    boolean equal(T gf);
    boolean notequal(T gf);
    boolean leq(T gf);
    boolean geq(T gf);
    boolean lt(T gf);
    boolean gt(T gf);
}
