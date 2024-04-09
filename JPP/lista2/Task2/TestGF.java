
public class TestGF {

  public static void main(String[] args) {
    testConstructors();
    testAccessors();
    testTypeConversions();
    testBasicOperations();
    testComparisonMethods();
  }
  
  public static void testConstructors() {
    // Test default constructor
    GF gf1 = new GF();
    if (gf1.getP() == 1234577) {
      System.out.println("Default constructor test passed.");
    } else {
      System.out.println("Default constructor test failed.");
    }

    // Test parameterized constructor
    GF gf2 = new GF(99991);
    if (gf2.getP() == 99991) {
      System.out.println("Parameterized constructor test passed.");
    } else {
      System.out.println("Parameterized constructor test failed.");
    }
  }

  public static void testAccessors() {
    // Test getValue method
    GF gf = new GF();
    gf.value = 1234;
    if (gf.getValue() == 1234) {
      System.out.println("getValue method test passed.");
    } else {
      System.out.println("getValue method test failed.");
    }

    // Test getP method
    if (gf.getP() == 1234577) {
      System.out.println("getP method test passed.");
    } else {
      System.out.println("getP method test failed.");
    }
  }

  public static void testTypeConversions() {
    GF gf = new GF();
    gf.value = 10;

    // Test toInt method
    if (gf.toInt() == 10) {
      System.out.println("toInt method test passed.");
    } else {
      System.out.println("toInt method test failed.");
    }

    // Test toLong method
    if (gf.toLong() == 10L) {
      System.out.println("toLong method test passed.");
    } else {
      System.out.println("toLong method test failed.");
    }

    // Test toBoolean method
    if (gf.toBoolean()) {
      System.out.println("toBoolean method test passed.");
    } else {
      System.out.println("toBoolean method test failed.");
    }

    // Test toFloat method
    if (gf.toFloat() == 10.0f) {
      System.out.println("toFloat method test passed.");
    } else {
      System.out.println("toFloat method test failed.");
    }

    // Test toDouble method
    if (gf.toDouble() == 10.0) {
      System.out.println("toDouble method test passed.");
    } else {
      System.out.println("toDouble method test failed.");
    }
  }

  public static void testBasicOperations() {
    GF gf1 = new GF();
    gf1.value = 10;
    GF gf2 = new GF();
    gf2.value = 5;

    // Test arithmetic operations
    gf1.increseValue(gf2);
    if (gf1.value == 15) {
      System.out.println("increseValue method test passed.");
    } else {
      System.out.println("increseValue method test failed.");
    }

    gf1.decreseValue(gf2);
    if (gf1.value == 10) {
      System.out.println("decreseValue method test passed.");
    } else {
      System.out.println("decreseValue method test failed.");
    }

    gf1.multiplyByValue(gf2);
    if (gf1.value == 50) {
      System.out.println("multiplyByValue method test passed.");
    } else {
      System.out.println("multiplyByValue method test failed.");
    }

    gf1.divideByValue(gf2);
    gf1.divideByValue(gf2);
    if (gf1.value == 2) {
      System.out.println("divideByValue method test passed.");
    } else {
      System.out.println("divideByValue method test failed.");
      System.out.println(gf1);
    }
  }

  public static void testComparisonMethods() {
    GF gf1 = new GF(17);
    gf1.value = 10;
    GF gf2 = new GF(17);
    gf2.value = 5;

    // Test comparison methods
    if (gf1.equals(gf1)) {
      System.out.println("Equals method test passed.");
    } else {
      System.out.println("Equals method test failed.");
    }

    if (!gf1.equals(gf2)) {
      System.out.println("Equals method test passed.");
    } else {
      System.out.println("Equals method test failed.");
    }

    if (!gf1.leq(gf2)) {
      System.out.println("leq method test passed.");
    } else {
      System.out.println("leq method test failed.");
    }

    if (!gf1.lt(gf2)) {
      System.out.println("lt method test passed.");
    } else {
      System.out.println("lt method test failed.");
    }

    if (gf1.geq(gf2)) {
      System.out.println("geq method test passed.");
    } else {
      System.out.println("geq method test failed.");
    }

    if (gf1.gt(gf2)) {
      System.out.println("gt method test passed.");
    } else {
      System.out.println("gt method test failed.");
    }
  }
}