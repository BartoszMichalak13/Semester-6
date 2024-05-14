with Ada.Command_Line; 
with Ada.Text_IO; use Ada.Text_IO;
with philosophers; use philosophers;

procedure philorun is
  NumPhilosophers: Natural;
  EatenEnough: Natural;
begin

  if Ada.Command_Line.Argument_Count /= 2 then
    Ada.Text_IO.Put_Line("Usage: philosophers <NumPhilosophers> <EatenEnough>");
    return;
  end if;

   -- Parse command-line arguments
  NumPhilosophers := Natural'Value(Ada.Command_Line.Argument(1));
  EatenEnough := Natural'Value(Ada.Command_Line.Argument(2));

  Put_Line("#Philosophers =" & Natural'Image(NumPhilosophers));
  Put_Line("#Dininigs =" & Natural'Image(EatenEnough));
  --  for i in 1..NumPhilosophers loop
  --    PhilosopherArray(i).SetPhilosopher(i, PhilosopherForks);
  --    --  MyPhilosopherArray(i).SetPhilosopher(i);
  --  end loop;

  -- Run the simulation
  Simulation( NumPhilosophers, EatenEnough );
end philorun;
