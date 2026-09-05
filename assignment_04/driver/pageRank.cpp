void pageRank(vector<int>& row_ptr,vector<int>& col_ind,double d,double epsilon,int max_iter,int V) {

    vector<double> pr(V,1.0/V);
    vector<double> new_pr(V);

    for(int iter=0;iter<max_iter;iter++) {

        double base = (1.0-d)/V;
        double dangling_sum = 0.0;

        for(int u=0;u<V;u++) {
            int start=row_ptr[u];
            int end=row_ptr[u+1];

            if (start==end) {
                dangling_sum += pr[u];
            }
        }
        double dangling_contribution=d*dangling_sum/V;

        for(int v=0;v<V;v++) {
            new_pr[v]=base+dangling_contribution;
        }

    
        for(int u=0;u<V;u++) {

            int start=row_ptr[u];
            int end=row_ptr[u+1];

            int outdegree=end-start;
            if (outdegree==0)
                continue;

            double contribution=d*pr[u]/outdegree;

            for (int edge=start;edge<end;edge++) {
                int v=col_ind[edge];
                new_pr[v]+=contribution;
            }
        }

        // Calculate total change
        double change=0.0;
        for(int v=0;v<V;v++) {
            change+=abs(new_pr[v]-pr[v]);
        }
        pr.swap(new_pr);
        if(change <= epsilon) {
            cout<<"Converged after "<<iter+1<<"iterations\n";
            break;
        }
    }

    cout<<fixed<<setprecision(10);

    for(int v=0;v<V;v++) {
        cout<<v<<" "<<pr[v]<<'\n';
    }
}