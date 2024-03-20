package Wrapper is
   --  Declare an Ada function spec for Get_Num, then use
   --  C function get_num for the implementation.
  function Factorial_Loop(N : Long_Long_Integer) return Long_Long_Integer;
  pragma Import (C, Factorial_Loop, "factorial_loop");   
   
  function Factorial_Recursive(N : Long_Long_Integer) return Long_Long_Integer;
  pragma Import (C, Factorial_Recursive, "factorial_recursive");   
   
  function GCD_Loop(A, B : Integer) return Integer;
  pragma Import (C, GCD_Loop, "gcd_loop");   
  
  function GCD_Recursive(A, B : Integer) return Integer;
  pragma Import (C, GCD_Recursive, "gcd_loop");   
   
   -- Define Diophantine_Solution type
  type Diophantine_Solution is record
    X, Y : Integer;
  end record;

  function Solve_Diophantine_Loop(A, B, C : Integer) return Diophantine_Solution;
  pragma Import (C, Solve_Diophantine_Loop, "solve_diophantine_loop");   

  function Solve_Diophantine_Recursive(A, B, C : Integer) return Diophantine_Solution;
  pragma Import (C, Solve_Diophantine_Recursive, "solve_diophantine_recursive");   

end Wrapper;
