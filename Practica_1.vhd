-------------------------------------------------------------------------------
--
-- Company : CETYS Universidad
-- Engineer: Cristobal Capiz
-- 
-- Create Date:    09/02/2017 06:57:18
-- Project Name:   Practica_1
-- Module Name:    Practica_1.vhd
-- Description:
--
-- Additional Comments:
--
-------------------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;  -- Para std_logic
use IEEE.numeric_std.all;     -- Para unsigned

entity Practica_1 is
   port( A,B : in std_logic_vector (3 downto 0);
		 oper : in std_logic;
		 Co,Sig : out std_logic;
		 S : out std_logic_vector (3 downto 0));
end Practica_1;

architecture arq1 of Practica_1 is
begin

process (A,B,oper)
variable temp, DA, DB : std_logic_vector (4 downto 0) := "00000";
begin
	DA := '0' & A;
	DB := '0' & B;
	if oper = '0' then
		temp := std_logic_vector(unsigned(DA) + unsigned(DB));
		if unsigned(temp) > 9 then
			temp := std_logic_vector(unsigned(temp) + 6);
			Co <= '1';
		else
			Co <= '0';
		end if;
	else
		temp := std_logic_vector(unsigned(DA) - unsigned(DB));
		if temp(3) = '1' then
			temp := std_logic_vector(unsigned(not temp) + 1);
			sig <= '1';
		else
			sig <= '0';
		end if;
	end if;
	S <= temp(3 downto 0);
end process;

end arq1;
