function dados=KalmanAccelC(dT,tamanho,f)
%kalman 1d com integração
    %incializa
    %xk=[a;v;p]
    Xk=zeros(3,tamanho);
    Xk_prev=zeros(3,1);
    X_pred =Xk_prev;
    H=[1,0,0];
    A=[1,0,0;dT,1,0;dT^2 /2, dT,1];
    Pk_prev=eye(3);
    I=eye(3);
    vvar=400*9.81*1e-6 *sqrt(dT);
    wvar=[vvar;vvar*dT;vvar*dT^2 /2];
    n=3;
    Q=wvar*wvar.' * dT;
    R=vvar^2;
    for i=1:tamanho
        z=f(i);
        v=randn(1) * vvar;
        w=randn(n,1) .* wvar;
        %predicao
        X_pred=A*Xk_prev+w;
        P_pred=A*Pk_prev*(A.')+Q;
        %atualização
        Kk=P_pred*(H.')/(H*P_pred*(H.')+R);
        Xk(:,i)=X_pred+Kk*(z-H*X_pred - v);
        Pk=(I-Kk*H)*P_pred*((I-Kk*H).')+Kk*R*(Kk.');
        Xk_prev=Xk(:,i);
        %anteriores
        Pk_prev=Pk;
    end
    dados=array2table(Xk.','VariableNames',{'Accel','Velocidade','Deslocamento'});
end