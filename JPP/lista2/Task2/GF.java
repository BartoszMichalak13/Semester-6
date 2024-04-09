public class GF {
  private final long p;
  private long modPow(GF gf, long exp) {
    if (exp == 0) {
      return 1;
    }
    long prev_gf = 1;
    final long gf_val = gf.value;
    while (exp > 0) {
      prev_gf *= gf_val;
      prev_gf %= p;
      --exp;
    }
    return prev_gf;
  }

  public long value;
  public GF() {
    this.p = 1234577;
  }
  public GF(final long p) {
    this.p = p;
  }
  public long getP() {
    return this.p;
  }
  public long getValue() {
    return this.value;
  }

  public int toInt() {
    return (int) this.value;
  }
  public long toLong() {
    return (long) this.value;
  }
  public boolean toBoolean() {
    return this.value != 0;
  }
  public float toFloat() {
    return (float) this.value;
  }
  public double toDouble() {
    return (double) this.value;
  }

  //should deal with sys.out
  @Override
  public String toString() {
    return Long.toString(this.value);
  }


  // TODO dec, inc, mul and div, what if value not set?
  public void setValue(final GF gf) {
    this.value = gf.value;
  }
  public void decreseValue(final GF gf) {
    try {
      this.value = (this.value - gf.value) % this.p;
    } catch (Exception e) {
      System.out.println(e);
    }
  }
  public void increseValue(final GF gf) {
    try {
      this.value = (this.value + gf.value) % this.p;
    } catch (Exception e) {
      System.out.println(e);
    }
  }
  public void multiplyByValue(final GF gf) {
    try {
      this.value = (this.value * gf.value) % this.p;
    } catch (Exception e) {
      System.out.println(e);
    }
  }
  public void divideByValue(final GF gf) {
    try {
      this.value = (this.value * modPow(gf,this.p-2)) % this.p;
    } catch (Exception e) {
      System.out.println(e);
    }
  }


  public GF plus(final GF gf) {
    GF gf3 = new GF();
    try {
      gf3.value = (this.value + gf.value) % this.p;
    } catch (Exception e) {
      System.out.println(e);
    }
    return gf3;
  }
  public GF minus(final GF gf) {
    GF gf3 = new GF();
    try {
      gf3.value = (this.value - gf.value) % this.p;
    } catch (Exception e) {
      System.out.println(e);
    }
    return gf3;
  }
  public GF multiply(final GF gf) {
    GF gf3 = new GF();
    try {
      gf3.value = (this.value * gf.value) % this.p;
    } catch (Exception e) {
      System.out.println(e);
    }
    return gf3;
  }
  public GF divide(final GF gf) {
    GF gf3 = new GF();
    try {
      gf3.value = (this.value * modPow(gf,this.p-2)) % this.p;
    } catch (Exception e) {
      System.out.println(e);
    }
    return gf3;
  }

  public boolean equal(final GF gf) {
    return (Long.compare(this.value, gf.value) == 0) 
           && (Long.compare(this.p, gf.p) == 0);
  }
  public boolean notequal(final GF gf) { 
    return !(Long.compare(this.value, gf.value) == 0) 
           || !(Long.compare(this.p, gf.p) == 0);
  }
  public boolean leq(final GF gf) {
    return (Long.compare(this.value, gf.value) <= 0) 
           && (Long.compare(this.p, gf.p) == 0);
  }
  public boolean geq(final GF gf) {
    return (Long.compare(this.value, gf.value) >= 0) 
           && (Long.compare(this.p, gf.p) == 0);
  }
  public boolean lt(final GF gf) {
    return (Long.compare(this.value, gf.value) < 0) 
           && (Long.compare(this.p, gf.p) == 0);
  }
  public boolean gt(final GF gf) {
    return (Long.compare(this.value, gf.value) > 0) 
           && (Long.compare(this.p, gf.p) == 0);
  }

}