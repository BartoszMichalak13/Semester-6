-- my_library.adb

with Ada.Text_IO; use Ada.Text_IO;
with My_Library; use My_Library;

package body My_Library is
  function Factorial_loop(N : Long_Long_Integer) return Long_Long_Integer is
    Result : Long_Long_Integer := 1;
  begin
    if N = 0 then
      return Result;
    else
      for I in 1 .. N loop
        begin
          Result := Result * I;
        exception
          when Constraint_Error =>
            --  Put_Line("Error: Factorial_loop of " & Long_Long_Integer'Image(N) & " overflows.");
            --  return Long_Long_Integer'Last; -- Return the maximum representable value
            return -1;
        end;
      end loop;
      return Result;
    end if;
  end Factorial_loop;

  function Factorial_recursive(N : Long_Long_Integer) return Long_Long_Integer is
    Result : Long_Long_Integer := 1;
  begin
    if N = 0 then
      return Result;
    else
    begin
      Result :=  N * Factorial_recursive(N - 1);
      exception
          when Constraint_Error =>
            --  Put_Line("Error: Factorial_loop of " & Long_Long_Integer'Image(N) & " overflows.");
            --  return Long_Long_Integer'Last; -- Return the maximum representable value
            return 0;
      end;
      return Result;
    end if;
  end Factorial_recursive;

  function Swap(A, B : Long_Long_Integer) return Swap_Array is
    Temp : Long_Long_Integer;
    Result : Swap_Array;
  begin
    Result(1) := A; -- Store original values
    Result(2) := B;
    
    if B > A then
      Temp := A;
      Result(1) := B;
      Result(2) := Temp;
    end if;
    
    return Result;
  end Swap;
  -- Function to calculate the greatest common divisor (GC_loopD)
  function GCD_loop(A, B : Long_Long_Integer) return Long_Long_Integer is
    Temp : Long_Long_Integer;
    nice_A : Long_Long_Integer;
    nice_B : Long_Long_Integer;
    Swapped : Swap_Array;
  begin
    -- Swap(A, B);
    nice_A := A;
    nice_B := B;
    Swapped := Swap(A, B);
    nice_A := Swapped(1);
    nice_B := Swapped(2);
    while nice_B /= 0 loop
      Temp := nice_B;
      nice_B := nice_A mod nice_B;
      nice_A := Temp;
    end loop;
    return nice_A;
  end GCD_loop;

  -- Function to calculate the greatest common divisor (GCD_recursive) recursively
  function GCD_recursive(A, B : Long_Long_Integer) return Long_Long_Integer is
  begin
    if B = 0 then
      return A;
    else
      return GCD_recursive(B, A mod B);
    end if;
  end GCD_recursive;

  -- Function to solve the linear Diophantine equation
  function Solve_Diophantine_loop(A, B, C : Long_Long_Integer) return Diophantine_Solution is
    Gcd_Resu_looplt : Long_Long_Integer;
    Old_S, S, Old_R, R, Quotient, Bezout_T : Long_Long_Integer;
    Remainder, Tmp : Long_Long_Integer;
    --  Is_multiple_of_GCD_loop : Float;
  begin
    Gcd_Resu_looplt := GCD_loop(A, B);
    Remainder := C rem Gcd_Resu_looplt;
    if Remainder = 0 then
      -- Calculating the Diophantine equation solution
      Old_S := 1;
      S := 0;
      Old_R := A;
      R := B;

      while R /= 0 loop
        Quotient := Old_R / R;
        Tmp := Old_R;
        Old_R := R;
        R := Tmp - Quotient * R;
        Tmp := Old_S;
        Old_S := S;
        S := Tmp - Quotient * S;
      end loop;

      if B /= 0 then
        Bezout_T := (Old_R - Old_S * A) / B;
      else
        Bezout_T := 0;
      end if;

      return (X => Old_S * (C / Gcd_Resu_looplt), Y => Bezout_T * (C / Gcd_Resu_looplt));
    else
      Put_Line("Solution doesn't exist as " & 
              Long_Long_Integer'Image(C) & 
              " is not multpile of gcd_loop(" & 
              Long_Long_Integer'Image(A) & "," & 
              Long_Long_Integer'Image(B) & ")");
      --  return (X => Long_Long_Integer'First, Y => Long_Long_Integer'First);
      return (X => -1, Y => -1);
    end if;
  end Solve_Diophantine_loop;


  -- MULTIPLIER SHOULD ALWAYS BE SET TO 1
  function Solve_Diophantine_recursive_multiplier(A, B, C, Multiplier : Long_Long_Integer) return Diophantine_Solution is
      Gcd_Recursive_Result, Multiplier_modified : Long_Long_Integer;
      X, Y : Long_Long_Integer;
    begin
      Gcd_Recursive_Result := GCD_recursive(A, B);

      -- Adjust the multiplier accordingly
      if Multiplier = 1 then
        Multiplier_modified := Multiplier * C / Gcd_Recursive_Result;
      else 
        Multiplier_modified := Multiplier;
      end if;

      if C mod Gcd_Recursive_Result /= 0 then
        Put_Line("Solution doesn't exist as " & Long_Long_Integer'Image(C) & " is not a multiple of GCD_recursive(" & Long_Long_Integer'Image(A) & "," & Long_Long_Integer'Image(B) & ")");
        return (X => -1, Y => -1);
      else
        if B = 0 then
          return (X => Multiplier, Y => 0);
        else
          declare
            Solution : Diophantine_Solution := Solve_Diophantine_recursive_multiplier(B, A mod B, C, Multiplier_modified);
          begin
            X := Solution.X;
            Y := Solution.Y;
            return (X => Y, Y => Solution.X - (A / B) * Solution.Y);
          end;
        end if;
      end if;
    end Solve_Diophantine_recursive_multiplier;


  --  Function to solve the linear Diophantine equation recursivelY
  function Solve_Diophantine_recursive(A, B, C : Long_Long_Integer) return Diophantine_Solution is
  begin
    return Solve_Diophantine_recursive_multiplier(A, B, C, 1);
  end Solve_Diophantine_recursive;


end My_Library;

