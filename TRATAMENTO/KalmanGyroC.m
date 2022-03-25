function dados=KalmanGyroC(dT,tamanho,f)
%kalman 1d com integração
    %incializa
    %xk=[gz; oz]
    Xk=zeros(2,tamanho);
    Xk_prev=zeros(2,1);
    X_pred=Xk_prev;
    H=[1,0];
    A=[1,0;dT,1];
    Pk_prev=eye(2);
    I=eye(2);
    vvar=0.05;
    wvar=[vvar;vvar*dT];
    n=2;
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
        Xk(:,i)=rem(Xk(:,i),360);
        Pk=rem(Pk,360);
        Xk_prev=Xk(:,i);
        %anteriores
        Pk_prev=Pk;
    end
    dados=array2table(Xk.','VariableNames',{'Gyro','Angulo'});
    
end