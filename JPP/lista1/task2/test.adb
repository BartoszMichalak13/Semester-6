with Ada.Command_Line;
with Ada.Text_IO;
with My_Library;

procedure Test is
    use Ada.Text_IO;
    package My_Lib renames My_Library;
    Solution : My_Lib.Diophantine_Solution;
    A, B, C: Long_Long_Integer;
    res : Long_Long_Integer;
begin
    -- Check if enough command-line arguments are provided
    if Ada.Command_Line.Argument_Count < 3 then
        Put_Line("Usage: ./test <A> <B> <C>");
        return;
    end if;

    -- Parse command-line arguments
    A := Long_Long_Integer'Value(Ada.Command_Line.Argument(1));
    B := Long_Long_Integer'Value(Ada.Command_Line.Argument(2));
    C := Long_Long_Integer'Value(Ada.Command_Line.Argument(3));

    res := My_Lib.Factorial_recursive(A);
    if res = 0 then
      Put_Line("Error: Factorial_recursive of " & Long_Long_Integer'Image(A) & " overflows.");
    else
      Put_Line( Long_Long_Integer'Image(C) & "!(recursive) = " & 
            Long_Long_Integer'Image(res)); 
    end if;

    res := My_Lib.Factorial_loop(A);
    if res = -1 then
      Put_Line("Error: Factorial_loop of " & Long_Long_Integer'Image(A) & " overflows.");
    else
      Put_Line( Long_Long_Integer'Image(C) & "!(loop) = " & 
            Long_Long_Integer'Image(My_Lib.Factorial_loop(A))); 
    end if;


    Put_Line("NWD("& Long_Long_Integer'Image(A) & ", " & 
            Long_Long_Integer'Image(B) & ")(recursive) = " & 
            Long_Long_Integer'Image(My_Lib.GCD_recursive(A, B)));
    Put_Line("NWD("& Long_Long_Integer'Image(A) & ", " & 
            Long_Long_Integer'Image(B) & ")(loop) = " & 
            Long_Long_Integer'Image(My_Lib.GCD_loop(A, B)));
    Solution := My_Lib.Solve_Diophantine_recursive(A, B, C);
    Put_Line("Solution to the Diophantine equation(recursive) " & 
            Long_Long_Integer'Image(A) & "x + " & 
            Long_Long_Integer'Image(B) & "y = " & 
            Long_Long_Integer'Image(C) & ": x = " & 
            Long_Long_Integer'Image(Solution.X) & ", y = " & 
            Long_Long_Integer'Image(Solution.Y));

    Solution := My_Lib.Solve_Diophantine_loop(A, B, C);
    Put_Line("Solution to the Diophantine equation(loop) " & 
            Long_Long_Integer'Image(A) & "x + " & 
            Long_Long_Integer'Image(B) & "y = " & 
            Long_Long_Integer'Image(C) & ": x = " & 
            Long_Long_Integer'Image(Solution.X) & ", y = " & 
            Long_Long_Integer'Image(Solution.Y));
    end Test;