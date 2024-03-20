with Ada.Text_IO;

package My_Library is
    type Swap_Array is array (1..2) of Long_Long_Integer;
    function Factorial_loop(N : Long_Long_Integer) return Long_Long_Integer;
    function Factorial_recursive(N : Long_Long_Integer) return Long_Long_Integer;
    function GCD_loop(A, B : Long_Long_Integer) return Long_Long_Integer;
    function GCD_recursive(A, B : Long_Long_Integer) return Long_Long_Integer;
    type Diophantine_Solution is record
        X : Long_Long_Integer;
        Y : Long_Long_Integer;
    end record;
    function Solve_Diophantine_loop(A, B, C : Long_Long_Integer) return Diophantine_Solution;
    function Solve_Diophantine_recursive(A, B, C : Long_Long_Integer) return Diophantine_Solution;
end My_Library;
