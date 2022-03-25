function AT =IntTriang(x,y)
    %AT = matriz [x2;fx2] da integral triangular acumulativa de 
    %vetores de ponto x e y(x)
    %como e usado com medidas reais , x deve ser em segundos
    arguments
        x (1,:) {mustBeNumeric,mustBeReal}
        y (1,:) {mustBeNumeric,mustBeReal}
    end
    tamanho = length(x);
    if(tamanho ~= length(y))
        error("X e Y devem ter o mesmo tamanho!");
    elseif(tamanho<3)
        error("Vetor X muito pequeno!");            
    end
    n=10; %numero de pontos usado para cada intervalo, 10 tem maior convergencia
    integral_y = zeros(1,tamanho-1); % integral de cada intervalo 
    integral_x = integral_y; %pontos médios de cada intervalo
    for i=1:tamanho-1
        xi=x(i:i+1); %pontos nesse intervalo
        yi=y(i:i+1);
        integral_x(i) = mean(xi);
        integral_y(i) = IterIntTriang(xi,yi,n);
        if i > 1 %acumumlativa
            integral_y(i) = integral_y(i)+integral_y(i-1);
        end
        
    end
    % como a integração retorna a media entre pontos, vamos ajustar para o
    % intervalo dado onde x2 sao os pontos médios do intervalo
    AT = interp1(integral_x,integral_y,x,'pchip','extrap');
end

function AT = IterIntTriang (xn,yn,n)
% uma iteracao da integração por triangulos
% onde xo =[x0 xf] , fxo = [fx0 fxf] e n > 0
    arguments
        xn (1,:) {mustBeNumeric,mustBeReal}
        yn (1,:) {mustBeNumeric,mustBeReal}
        n (1,1) {mustBeScalarOrEmpty,mustBePositive}
    end
    x=interp1([1 n+2],xn,[1:n+2]);
    y=interp1(xn,yn,x);
    i = round((n+2)/2); % elemento xi entre x0 e xf escolhido o do meio 
    x0 = [x(1) x(i) x(1)];
    y0 = [0 0 y(1)];
    xf = [x(end) x(i) x(end)];
    yf = [0 0 y(end)];
    A0 = AreaTriangulo(x0,y0) ; %area incial
    Af = AreaTriangulo(xf,yf); %area final
    Ak = 0; %area intermediaria
    %soma de 1 a n+1 se comeca 
    % com x0, como index matlab x(1) = x0 , x1= x(2)
    %adicionar triangulos inferiores
    for k = 1:n+1
        xk = [x(k) x(i) x(k+1)];
        yk = [y(k) 0 y(k+1)];
        Ak = Ak + AreaTriangulo(xk,yk);
    end
    AT = A0 + Ak + Af;
end