x = [0,1,3,4,5];
y = [0, 1.24,2.34,6.12,8.40];
f1 = x;
f2 = x.^2;
p = polyfit(x,y,2);
%[7,15.65] leaving out the last point and then ploting best fit and then
%verifying


x1 = linspace(0,8);
y1 = polyval(p,x1);
figure
hold on
plot(x,y,'.')
plot(7,15.65,'o')
plot(x1,y1)
title("Cubic fit curve")
xlabel("n")
ylabel("cputime (1e-5)")
hold off

disp(p)