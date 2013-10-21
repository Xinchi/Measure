function data_analysis( filename )
%A function created by Max Gu to perform the data analysis
    threashol_d = 5;
    data_ = importdata(filename);
    total_No_of_Samples = size(data_,1)
    mean_ = mean(data_)
    std_ = std(data_)
    
    useful_ = data_((data_-mean(data_))<=threashol_d);
    total_No_of__Useful_Samples = size(useful_,1)
    
    std_useful_ = std(useful_)
    mean_useful_ = mean(useful_)
%     abnormal = data(data~=useful(:))
    stem(useful_,'LineStyle','none')

end

