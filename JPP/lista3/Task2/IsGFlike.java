// Define an interface combining all required properties
public interface IsGFlike<T> extends HasGetP<T>, 
        HasValue<T>, 
        HasConstructorWithLongParam<T>, 
        ArithmeticOperations<T>, 
        Comparisons<T>,
        ByValueOperations<T> {}
