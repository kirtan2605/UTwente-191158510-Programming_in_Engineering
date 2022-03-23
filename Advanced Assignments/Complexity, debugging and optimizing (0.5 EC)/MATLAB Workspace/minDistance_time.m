function d = minDistance_time(n)
% Given a set of 3D points specified by column vectors x,y,z, this
% function computes the minimum distance to the origin
x = 1:n;
y = 1:n;
z = 1:n;
tic;
for i = 1:100000
% compute distance for every point
d = sqrt(x.^2 + y.^2 + z.^2);
end
toc
% get minimum distance
d = min(d);
