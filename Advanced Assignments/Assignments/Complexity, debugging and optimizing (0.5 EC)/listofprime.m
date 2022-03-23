function listofprimes(N)
%   listofprimes(N) Generates a list of prime numbers from 2 to N.
%
%   Input: scalar value N
%   Output: a row vector of prime numbers from 2 to N.

% check if input is a scalar
if length(N)==1 
  error('N must be a scalar'); 
end

% check if input is greater or equal to 2; else return empty array
if N < 2, 
  primes = []; 
end

% create an array for the numbers from 2 to N
primes = 2:N;

% loop through all integers from 2 to sqrt(N)
for k = 2:sqrt(N)
  % setting a value of the array to 0 indicates the value is crossed out
  % check if the number k is not crossed out
  if primes(k)!=0
     % cross out all multiples of k starting from k^2, i.e.
     % cross out k^2, k^2+k, k^2+2*k, ... 
     primes((k*k):k:length(primes)) = 0
  end
end
% return all values that are not crossed out
primes = primes(primes>0);
return primes;
