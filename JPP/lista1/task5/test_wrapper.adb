with Ada.Command_Line; use Ada.Command_Line;
with Ada.Text_IO; use Ada.Text_IO;
with Wrapper;

procedure Test_Wrapper is
  -- Import the package containing function specs
  use Wrapper;
   
  Result : Integer;
  Result_Factorial : Long_Long_Integer;
  Diophantine_Result : Diophantine_Solution;
begin
  --  Check if there are enough command line arguments
  if Argument_Count < 3 then
    Put_Line ("Usage: ./test <integer_1> <integer_2> <integer_3>");
    return;
  end if;

  -- Parse command line arguments
  declare
    A : constant Integer := Integer'Value (Argument (1));
    B : constant Integer := Integer'Value (Argument (2));
    C : constant Integer := Integer'Value (Argument (3));
  begin
    -- Testing factorial loop function
    Result_Factorial := Factorial_Loop (Long_Long_Integer'Value(Integer'Image(A)));
    Put_Line ("Factorial Loop of" & Integer'Image (A) & ":" & Long_Long_Integer'Image (Result_Factorial));

    -- Testing factorial recursive function
    Result_Factorial := Factorial_Recursive (Long_Long_Integer'Value(Integer'Image(A)));
    Put_Line ("Factorial Recursive of" & Integer'Image (A) & ":" & Long_Long_Integer'Image (Result_Factorial));

    -- Testing GCD loop function
    Result := GCD_Loop (A, B);
    Put_Line ("GCD Loop of" & Integer'Image (A) & " and" & Integer'Image (B) & ":" & Integer'Image (Result));

    -- Testing GCD recursive function
    Result := GCD_Recursive (A, B);
    Put_Line ("GCD Recursive of" & Integer'Image (A) & " and" & Integer'Image (B) & ":" & Integer'Image (Result));

    -- Testing Diophantine Equation loop function
    Diophantine_Result := Solve_Diophantine_Loop (A, B, C);
    Put_Line ("Diophantine Equation Solution (Loop) for " & Integer'Image (A) & "x +" & Integer'Image (B) & "y =" & Integer'Image (C) & " is" & 
    " x =" & Integer'Image (Diophantine_Result.X) &
    " y =" & Integer'Image (Diophantine_Result.Y));

    -- Testing Diophantine Equation recursive function
    Diophantine_Result := Solve_Diophantine_Recursive (A, B, C);
    Put_Line ("Diophantine Equation Solution (Recursive) for " & Integer'Image (A) & "x +" & Integer'Image (B) & "y =" & Integer'Image (C) & " is" & 
    " x =" & Integer'Image (Diophantine_Result.X) &
    " y =" & Integer'Image (Diophantine_Result.Y));
  end;
end Test_Wrapper;