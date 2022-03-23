function t = complexity(n)
% initialize matrix

M = rand(n);
N = rand(n);

tStart = cputime;
for i = 1:1000000
P = M*N;
end
tEnd = cputime - tStart;
disp(tEnd);
t = tEnd;
