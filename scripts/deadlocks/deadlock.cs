void UpdateLabel(string text) {
   lock(this) {
      if(MyLabel.InvokeNeeded) {
        IAsyncResult res =  MyLable.BeginInvoke(delegate() {
             MyLable.Text = text;
            });
         MyLabel.EndInvoke(res);
        } else {
             MyLable.Text = text;
        }
    }
}