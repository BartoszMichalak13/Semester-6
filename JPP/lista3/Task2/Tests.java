
public class Tests {
    public static void main(String[] args) {
        long p = args.length < 1 ? 1234567891 : Long.parseLong(args[0]);
        GF gf = new GF(p);
         System.out.println("tst");
        // Creating DHSetup object
        DHSetup<GF> dhSetup = new DHSetup<>(gf);
         System.out.println("tst");
         System.out.println("dhSetup.getp " + dhSetup.getP());

        // Creating two User objects
        User<GF> alice = new User<>(dhSetup, gf);
        User<GF> bob = new User<>(dhSetup, gf);
         System.out.println("tst");

        // Getting public keys
        GF alicePublicKey = alice.getPublicKey();
        GF bobPublicKey = bob.getPublicKey();
         System.out.println("tst");

        // Exchanging public keys
        alice.setKey(bobPublicKey);
        bob.setKey(alicePublicKey);
         System.out.println("tst");

        // Test encryption and decryption
        GF plaintext = new GF(42, p);
        GF encrypted = alice.encrypt(plaintext);
        GF decrypted = bob.decrypt(encrypted);

        System.out.println("Plaintext: " + plaintext.getValue());
        System.out.println("Encrypted: " + encrypted.getValue());
        System.out.println("Decrypted: " + decrypted.getValue());
    }
}