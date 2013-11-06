function data_analysis( filename, name )
%A function created by Max Gu to perform the data analysis
    cmap = hsv(30);
    threashold_ = 0.001;
    size_of_filename = size(filename)
    size_of_name = size(name)
    figure;

    for i = 1:size(filename,1)
        i
        
    data_ = importdata(filename{i,1});
%     total_No_of_Samples = size(data_,1)
%     mean_ = mean(data_)
     std_ = std(data_);
    
%         useful_ = data_((data_-median(data_))<=threashold_*std_);
       useful_ = data_;
     total_No_of__Useful_Samples = size(useful_,1);
    
     std_useful_ = std(useful_)
    mean_useful_ = mean(useful_)
%     function_overhead = mean_useful_-67
%      abnormal = data(data~=useful(:))
    hold on
    stem(useful_,'LineStyle','none', 'Color',cmap(2*i,:))
    
%     legend(name{i},'Location','Northeast')

    end

    legend(name{1:size(name)})
    xlabel('Times'), ylabel('Cycles')
    axis([0,5000,400,650])

end

