with Ada.Text_IO; use Ada.Text_IO;
--  with Ada.Command_Line;
--  with Ada.Containers.Vectors;

--  DZIALA DLA 5 NIE DLA PODANYCH JAKO ARGUMENTY
package body Philosophers is

procedure Simulation ( NumPhilosophers : Natural;
                         EatenEnough : Natural ) is
  protected type Fork is
    -- fid's are for debuging purposes
    entry PickUp(ID: Natural; fid: Natural);
    entry PutDown(ID: Natural; fid: Natural);
    function IsTaken return Boolean; -- Function to check if fork is taken
  private
    Taken : Boolean := False;
  end Fork;

  -- all available forks
  PhilosopherForks : array(1..NumPhilosophers) of Fork; 

  protected body Fork is
    --  entry PickUp(ID: Natural) 
    entry PickUp(ID: Natural; fid: Natural) 
      when not Taken is
    begin
      --  Put_Line("fork " & Natural'Image(fid) &" PickUp by " & Natural'Image(ID));
      Taken := True;
    end PickUp;
    entry PutDown(ID: Natural; fid: Natural) 
      when Taken is
    begin
        --  Put_Line("fork " & Natural'Image(fid) &" PutDown by " & Natural'Image(ID));
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
        PhilosopherForks(LeftFork).PickUp(ID, LeftFork);
        if not PhilosopherForks(RightFork).IsTaken then
          PhilosopherForks(RightFork).PickUp(ID, RightFork);
          Eaten := Eaten + 1;
          Put_Line("Philosopher " & Natural'Image(ID) & " Eaten = " &
            Natural'Image(Eaten) & "/" & Natural'Image(EatenEnough));

          PhilosopherForks(RightFork).PutDown(ID, RightFork);
          PhilosopherForks(LeftFork).PutDown(ID, LeftFork);
          if Eaten >= EatenEnough then
            Put_Line("Philosopher " & Natural'Image(ID) & " is Full");
            exit;
          end if;
        else 
          PhilosopherForks(LeftFork).PutDown(ID, LeftFork);
        end if;
      end if;
    end loop;
  end Philosopher;

  PhilosopherArray : array(1..NumPhilosophers) of Philosopher;

begin
  for i in 1..NumPhilosophers loop
    PhilosopherArray(i).SetPhilosopher(i);
  end loop;
end Simulation;
end Philosophers;