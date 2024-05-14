with Ada.Text_IO; use Ada.Text_IO;
--  with Ada.Command_Line;
--  with Ada.Containers.Vectors;

--  DZIALA DLA 5 NIE DLA PODANYCH JAKO ARGUMENTY
package body Philosophers is

procedure Simulation ( NumPhilosophers : Natural;
                         EatenEnough : Natural ) is
  --Number of Philosophers
  --  NumPhilosophers : Natural := 5;
  --  NumPhilosophers : Natural;
  -- how much to eat
  --  EatenEnough : Natural := 100; 
  --  EatenEnough : Natural; 
  --  type PhilosopherID is range 1 .. NumPhilosophers;

  protected type Fork is
    entry PickUp(ID: Natural);
    entry PutDown(ID: Natural);
    function IsTaken return Boolean; -- Function to check if fork is taken
  private
    Taken : Boolean := False;
  end Fork;

  -- all available forks
  PhilosopherForks : array(1..NumPhilosophers) of Fork; 
  --  type PhilosopherForksArray is array(Positive range <>) of Fork; 
  --  PhilosopherForks: PhilosopherForksArray;

  protected body Fork is
    entry PickUp(ID: Natural) 
      when not Taken is
    begin
      Taken := True;
    end PickUp;
    entry PutDown(ID: Natural) 
      when Taken is
    begin
      Taken := False;
    end PutDown;
    function IsTaken return Boolean is
    begin
      return Taken;
    end IsTaken;
  end Fork;

  task type Philosopher is
    entry SetPhilosopher(I: Natural);
  end Philosopher;

  task body Philosopher is
    LeftFork, RightFork : Natural;
    Eaten: Natural := 0;
    ID: Natural := 0;
  begin
  accept SetPhilosopher ( I : Natural ) do
    ID := I;
    LeftFork := I;
    RightFork := (I mod NumPhilosophers) + 1;    
    Put_Line("Philosopher " & Natural'Image(I) & " eats with " & 
      Natural'Image((I mod NumPhilosophers) + 1) & " and " & Natural'Image(I));
  end SetPhilosopher;
    loop
      if not PhilosopherForks(LeftFork).IsTaken then
        PhilosopherForks(LeftFork).PickUp(ID);
        if not PhilosopherForks(RightFork).IsTaken then
          PhilosopherForks(RightFork).PickUp(ID);
          Eaten := Eaten + 1;
          Put_Line("Philosopher " & Natural'Image(ID) & " Eaten = " &
            Natural'Image(Eaten) & "/" & Natural'Image(EatenEnough));

          PhilosopherForks(RightFork).PutDown(ID);
          PhilosopherForks(LeftFork).PutDown(ID);
          if Eaten >= EatenEnough then
            Put_Line("Philosopher " & Natural'Image(ID) & " is Full");
            exit;
          end if;
        else 
          PhilosopherForks(LeftFork).PutDown(ID);
        end if;
      end if;
    end loop;
  end Philosopher;

  PhilosopherArray : array(1..NumPhilosophers) of Philosopher;

begin
  --  if Ada.Command_Line.Argument_Count /= 2 then
  --    Ada.Text_IO.Put_Line("Usage: philosophers <NumPhilosophers> <EatenEnough>");
  --    return;
  --  end if;

  --   -- Parse command-line arguments
  --  NumPhilosophers := Natural'Value(Ada.Command_Line.Argument(1));
  --  EatenEnough := Natural'Value(Ada.Command_Line.Argument(2));

  --  --  declare 
  --  --    PhilosopherForks: PhilosopherForksArray(1..NumPhilosophers)

  --  --  MyPhilosopherArray := CreatePhilosopherArray(NumPhilosophers);
  --  --  PhilosopherForks := CreatePhilosopherForksArray(NumPhilosophers);

  --  Put_Line("#Philosophers =" & Natural'Image(NumPhilosophers));
  --  Put_Line("#Dininigs =" & Natural'Image(EatenEnough));
  for i in 1..NumPhilosophers loop
    PhilosopherArray(i).SetPhilosopher(i);
    --  MyPhilosopherArray(i).SetPhilosopher(i);
  end loop;

end Simulation;
end Philosophers;